using Microsoft.VisualStudio.TestTools.UnitTesting;
using ACMEE;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ACMEE.Tests
{
    [TestClass()]
    public class ProductTests
    {
        [TestMethod()]
        
        public void sayHello_parametriedconstructorTest()
        {
            var currentproduct = new Product( "book", "sbn no 12t68t46", 1);
           
            
            var expected = "hello book (1)  sbn no 12t68t46";
            var actual = currentproduct.sayHello();
            Assert.AreEqual(expected, actual);
            
        }
        public void sayHelloTest()
        {
            var currentproduct = new Product();
            currentproduct.ProductName = "book";
            currentproduct.ProductID = 1;
            currentproduct.Discription = "sbn no 12t68t46";
            var expected = "hello book (1)  sbn no 12t68t46";
            var actual = currentproduct.sayHello();
            Assert.AreEqual(expected, actual);

        }
    }
}