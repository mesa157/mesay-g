using System;
using System.Collections.Generic;

namespace newmesaygradebook
{
    class Program
    {
        
        static void main(string[] args)
         {
            var book = new Book("mesay's grade book");
            book.AddGrade(90.5);
            book.AddGrade(89.1);
            book.AddGrade(75.3);
            var  stats = book.GetStatistics();
            Console.WriteLine($"the lowest grade is {stats.Low}");
            Console.WriteLine($"the HIGHEST grade is {stats.High}");
            Console.WriteLine($"the average grade is {stats.Average:N1}");

        }
        
    }
}
