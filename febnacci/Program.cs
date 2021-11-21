using System;

namespace febnacci
{
    class Program
    {
       public class quadratic
        {
            public double A { set; get; }
            public double B { set; get; }
            public double C { set; get; }
           


            double result = 0.0;



          public  quadratic()
            {

            }
          public  quadratic(double a , double b, double c)
            {
                A =a;
                B = b;
                C = c;

               
            }
             
            public void maths(double A, double B ,double C)
            {
                result = B*B;
                result = result + 4 * A * C;
                result = Math.Sqrt(result);
               
              
                
                
                if (A != 0)
                {
                    result = result / 2;
                    result = result / A;
                    Console.WriteLine($"root result : {result}");
                 
                }
                else
                    Console.WriteLine("error message");
                
            }

        }
        static void Main(string[] args)
        {
            quadratic squad = new quadratic();
            squad.maths(1, 1, -2);
            Console.WriteLine($"ROOTS: {squad}");
        }
    }
}
