using System;

namespace ConsoleApp4
{
    class Program
    { 

    public class car
    {
        public car()
        {
            Console.WriteLine("car instance created");
        }
        public car(string brand, string model, int plateNumber) : this()
        {
            this.Brand = brand;
            this.PlateNumber = plateNumber;
            this.Model = model;
            Console.WriteLine("prametres intalized");
        }


        
        public string Brand
        {
                get; set; }
            
            
        public string Model { get; set; }
        
        public int PlateNumber { get; set; }
            public void  GetBrand(string Brand , string Model)
            {
                var carbook = Brand + " :" + Model;
               
                
            }
            public void GetModel(string Model)
            {
                Model = "yaris 2019";
                Model = "corolla 2021";
                
            }
           public void getPlate(int plateNumber)
            {
                plateNumber = 472398573;
                plateNumber = 494734934;
            }
          

    }

       public static void Main(string[] args)
        {
            car cartype = new car();
            cartype.GetModel("toyota");
            
            Console.WriteLine($"Hello World!  c", cartype);
        }
    }
}
