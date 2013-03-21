import unittest
from tests_utils import execute_test

class XSLTest(unittest.TestCase):
    def setUp(self):

    def simple_test(self, n):
       result = execute_test(["simple" + str(n) + ".xml", "-x simple" + str(n) + ".xsl"])
       f = open("simple" + str(n) + ".html", 'r')
       expected = f.read()
       f.close()
       assertEqual(result, expected)
        

    def test_simple1(self):
        simple_test(1)
   
   def test_simple2(self):
       simple_test(2)

   def test_simple3(self):
       simple_test(3)

if __name__ == '__main__':
    unittest.main()
