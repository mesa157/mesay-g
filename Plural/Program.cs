using System;
using System.Collections.Generic;
using System.Threading.Channels;

namespace Plural
{
    class Program
    {
        static void Main(string[] args)
        {
            
            var number = new  List<double>() { 2.3, 45, 34, 37 };
            number.Add(45.7);
            
            var result = 0.0;
            
         foreach(double Grade in number) {
                result += Grade;
             
            }
            result /= number.Count;
            Console.WriteLine(result);

        }
    }
}
