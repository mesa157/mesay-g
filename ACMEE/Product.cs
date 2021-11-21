using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ACMEE
{
   /// <summary>
   /// manage products created in the inventory
   /// </summary>
   public class Product
    {
        public Product()
        {
            Console.WriteLine("instance of a class created");
        }
        public Product(string productName, string discription, int productID):this()
        {
            this.ProductID = productID;
            this.Discription = discription;
            this.ProductName = productName;
            Console.WriteLine("parametrized constructor created");
        }
        private int productID;
        private string productName;
        public string ProductName
        {
            get{ return productName; }
            set {  productName = value; }
        }
        private string discription;
        public string Discription
        {
            get
            { return discription; }
            set
            { productName = value; }
        }
        public int ProductID
        {
            get{return ProductID; }
            set {  productID = value; }
        }
        public string sayHello()
        {
            return "hello" +" "+ productName +"(" + productID +")" + discription;
        }

    }
}
