#include "StringCalculator.h"
#include <cppunit/TestCaller.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestFixture.h>
#include <cppunit/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>

class StringCalculatorTest : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(StringCalculatorTest);
    CPPUNIT_TEST(test_add_with_empty_string);
    CPPUNIT_TEST(test_add_with_one_number);
    CPPUNIT_TEST(test_add_with_two_numbers);
    CPPUNIT_TEST(test_add_with_unknown_amount_of_numbers);
    CPPUNIT_TEST(test_add_with_new_lines_between_numbers);
    CPPUNIT_TEST(test_add_with_a_new_different_delimiter);
    CPPUNIT_TEST(test_add_negatives_not_allowed);
    CPPUNIT_TEST_SUITE_END();
    private:
        StringCalculator * calc;
    public:
        void setUp() {
            calc = new StringCalculator();
        }
        
        void tearDown() {
            delete calc;
        }

    void test_add_with_empty_string() {
        CPPUNIT_ASSERT_EQUAL( 0, calc->add(""));
    }

    void test_add_with_one_number() {
        CPPUNIT_ASSERT_EQUAL( 1, calc->add("1"));
    }
    
    void test_add_with_two_numbers() {
        CPPUNIT_ASSERT_EQUAL( 3, calc->add("1,2"));
    }

    void test_add_with_unknown_amount_of_numbers() {
        CPPUNIT_ASSERT_EQUAL(15, calc->add("1,2,3,4,5"));
    }
    
    void test_add_with_new_lines_between_numbers() {
        CPPUNIT_ASSERT_EQUAL(6, calc->add("1\n2,3"));
    }

    void test_add_with_a_new_different_delimiter() {
        CPPUNIT_ASSERT_EQUAL(3, calc->add("//;\n1;2"));
    }

    void test_add_negatives_not_allowed() {
        CPPUNIT_ASSERT_EQUAL( 3, calc->add("1,-2"));
    }
};


int main(int argc, char **argv) {
    CppUnit::TextTestRunner runner;

    CPPUNIT_TEST_SUITE_REGISTRATION(StringCalculatorTest);
    runner.addTest( CppUnit::TestFactoryRegistry::getRegistry().makeTest() );
    runner.run();
}