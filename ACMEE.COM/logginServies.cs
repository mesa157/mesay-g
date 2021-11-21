using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ACMEE.COM
{
    /// <summary>
    /// provide the loggin methods 
    /// </summary>
   public static  class logginServies
    {
        public static string logAction(string action)
        {
            var logtext = "Action" + action;
            Console.WriteLine(logtext);
            return logtext;
        }
    }
}
