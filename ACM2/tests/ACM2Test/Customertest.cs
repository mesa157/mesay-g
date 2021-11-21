using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using ACM2;
namespace ACM2Test
{
    [TestClass]
    public class Customertest
    {
        [TestMethod]
        public void FullNameTestValid()
        {
            Customer customer = new Customer
            {
                FirstName = "Bilbo",
                LastName = "Baggins"
        };
             string expected= "Baggins,Bilbo";
            string actual = customer.FullName;
            Assert.AreEqual(expected, actual);
        }
    }
}
