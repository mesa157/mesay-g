using Microsoft.VisualStudio.TestTools.UnitTesting;
using ACMEE.COM;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ACMEE.COM.Tests
{
    [TestClass()]
    public class logginServiesTests
    {
        [TestMethod()]
        public void logActionTest()
        {
            var expected = "action: test action";
            var actual = logginServies.logAction("action: test action");
            Assert.AreEqual(expected,actual);
        }
    }
}