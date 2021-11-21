using System;
using System.Collections.Generic;

namespace training_day
{
    class Program
    {
        static void Main(string[] args)
        {
          var numbers  = new  List<double>() { 23.4, 28.4 , 23.4};
            numbers.Add(30);
            numbers.Add(45.6);
            
            var result = numbers[0];

            result = result + numbers[1];
            result = result + numbers[2];

            Console.WriteLine(result);

            Console.WriteLine("Hello World!" );
        }
    }
}
