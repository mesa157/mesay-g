using System;
using System.Collections.Generic;

namespace ConsoleApp3
{
    class Program
    {
       
        static void Main(string[] args)
        {
            var number = new  List<double> { 4.4, 27.2, 47.2 };
            number.Add(47);
             var results = 0.0;
            var malti = 1.0;
            

            foreach(var  numbers  in number) 
            {
                results += numbers;
                malti *= numbers;
              

            }
            results += results/number.Count;
            malti = malti / results;

            Console.WriteLine($"numbers are:{results}");
            Console.WriteLine($"rms are : {malti}");
        }
    }
}
