C_COMPILER      = gcc
C_FLAGS         = -Wall -pedantic -g
MATH_LINK 		= -lm 
CUNIT_LINK      = -lcunit
CODE_COVERAGE 	= -lgcov --coverage
PERFORMANCE 	= -pg


# Generate a test executable for cascade limit
cascade_test: cascade_limit.c cascade_tests.c
	$(C_COMPILER) $(C_FLAGS) $^ -o $@ $(CUNIT_LINK)

# Generate a test executable for handle memory
handle_memory_test: handle_memory.c handle_memory_tests.c
	$(C_COMPILER) $(C_FLAGS) $^ -o $@ $(CUNIT_LINK)

# Generate a test executable for reference counting
reference_counting_test: reference_counting.c reference_counting_tests.c
	$(C_COMPILER) $(C_FLAGS) $^ -o $@ $(CUNIT_LINK)

# Run cascade limit test
run_cascade_test: cascade_test
	./cascade_test

# Run handle memory test
run_handle_memory_test: handle_memory_test
	./handle_memory_test

# Run reference counting test
run_reference_counting_test: reference_counting_test
	./reference_counting_test

#Run all tests
run_tests: cascade_test handle_memory_test reference_counting_test
	./cascade_test
	./handle_memory_test
	./reference_counting_test

# run valgrind on cascade limit test
mem_test_cascade: cascade_test
	valgrind --leak-check=full ./cascade_test

# run valgrind on handle memory test
mem_test_handle_memory: handle_memory_test
	valgrind --leak-check=full ./handle_memory_test

# run valgrind on reference counting test
mem_test_reference_counting: reference_counting_test
	valgrind --leak-check=full ./reference_counting_test

# run valgrind to check for memory leaks
mem_test: cascade_test handle_memory_test reference_counting_test
	valgrind --leak-check=full ./cascade_test
	valgrind --leak-check=full ./handle_memory_test
	valgrind --leak-check=full ./reference_counting_test

# Code coverage
coverage_cascade: Cascade_limit.c cascade_tests.c
	$(C_COMPILER) $(CODE_COVERAGE) $^ -o $@ $(CUNIT_LINK)
	./$@
	gcov -abcfu Cascade_limit.c $@-Cascade_limit.*
	lcov --capture --directory . --output-file coverage.info	
	genhtml coverage.info --output-directory=res_cascade

coverage_handle_memory: handle_memory.c handle_memory_tests.c
	$(C_COMPILER) $(CODE_COVERAGE) $^ -o $@ $(CUNIT_LINK)
	./$@
	gcov -abcfu handle_memory.c $@-handle_memory.*
	lcov --capture --directory . --output-file coverage.info	
	genhtml coverage.info --output-directory=res_handle_memory

coverage_reference_counting: reference_counting.c reference_counting_tests.c
	$(C_COMPILER) $(CODE_COVERAGE) $^ -o $@ $(CUNIT_LINK)
	./$@
	gcov -abcfu reference_counting.c $@-reference_counting.*
	lcov --capture --directory . --output-file coverage.info	
	genhtml coverage.info --output-directory=res_reference_counting


clean:
	rm -f *.o 
	rm -f cascade_test handle_memory_test reference_counting_test
	rm -f *.gcda *.gcno *.gcov
	rm -f coverage.info
	rm -rf res_cascade res_handle_memory res_reference_counting
	rm -f coverage_cascade coverage_handle_memory coverage_reference_counting
	

