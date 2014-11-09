#!/bin/sh

usage() {
  echo ""
  echo "Usage: $0 -makefile"
  echo "  - show extra LDFLAGS needed in Makefile for supporting TEST_MOCK" 
  echo "Usage: $0 -autotool"
  echo "  - show extra LDFLAGS needed in Makefile.am for supporting TEST_MOCK" 
  echo ""
  exit 1
}

if [ $# -ne 1 ] ; then
  usage
fi

makefile=`expr $1 : '^-makefile$'`
autotool=`expr $1 : '^-autotool$'`
if [ $makefile -ne 0 ] ; then
  echo ""
  echo "Please add the corresponding LDFLAGS to the Makefiles when a unit test"
  echo "requires the mock functions in the following files:"
  echo ""
elif [ $autotool -ne 0 ] ; then
  echo ""
  echo "Please add the following LDFLAGS to the corresponding Makefile.am"
  echo ""
else
  usage
fi

if [ $makefile -ne 0 ] ; then
  #source_codes=`ls -R | grep "\.[ch]$"`
  source_codes=`find . -type f -name "*.[ch]"`
  for file in $source_codes ; do 
    match=`expr $file : '^.*\/unit_test_helper\.h$'` 
    if [ $match -eq 0 ] ; then # ignore unit_test_helper.h
      echo $file
      #LDFLAGS=`echo $file | sed -n 's/.*\/\(.*\)\.[ch]/\1_LDFLAGS/p'`
      #sed -n "s/.*TEST_MOCK(\([^)]*\)).*/  "$LDFLAGS" += -Wl,-wrap,\1/p" $file
      sed -n "s/.*TEST_MOCK(\([^)]*\)).*/  LDFLAGS += -Wl,-wrap,\1/p" $file
    fi
  done
fi

if [ $autotool -ne 0 ] ; then
  makefile_ams=`find . -type f -name "Makefile.am"`
  for am in $makefile_ams ; do 
    echo $am
    # find all unit tests in TESTS
    tests=`sed -n "s/^[ \t]*TESTS[ \t]*=[ \t]*\(.*\)$/\1/p" $am`
    for test in $tests ; do
      #echo " "$test
      ldflags=`echo $test"_LDFLAGS += -Wl,-wrap,"`
      # find all source codes in _SOURCES
      sources=`sed -n "s/^[ \t]*"$test"_SOURCES[ \t]*=[ \t]*\(.*\)$/\1/p" $am`
      for code in $sources ; do
        match=`expr $code : 'unit_test_helper\.h'` 
        if [ $match -eq 0 ] ; then # ignore unit_test_helper.h
          file=`find . -type f -name "$code"`
          #echo "  "$code"("$file")"
          # find all TEST_MOCK in the source codes
          sed -n "s/.*TEST_MOCK(\([^)]*\)).*/  $ldflags\1/p" $file
        fi
      done
    done
  done
fi

exit 1;

