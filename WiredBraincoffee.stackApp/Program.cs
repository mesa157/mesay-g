using System;
using System.Collections.Generic;

namespace wierdBraincoffee
{
    class Program
    {
        static void Main(string[] args)
        {
            stackDoubles();
            stackString();
            Console.ReadLine();

        }

        private static void stackString()
        {
            var stack = new Stack<string>();
            stack.Push("wierd brain coffee");
            stack.Push("mesaysight");
            stack.Push("pluralsight");
            while(stack.Count>0)
            {
                Console.WriteLine(stack.Pop());
            }

        }

        private static void stackDoubles()
        {
            var stack = new Stack<double>();
            stack.Push(1.2);
            stack.Push(2.8);
            stack.Push(3.0);
            double sum = 0.0;

            while (stack.Count > 0)
            {
                double item = stack.Pop();
                Console.WriteLine($"Item: {item}");
                sum += item;
            }
            Console.WriteLine($"sum: {sum}");
        }
    }

    public class SimpleStack<typeholder>
    {
        private readonly typeholder[] _items;
        private int _currentIndex = -1;
        public SimpleStack() =>  _items = new typeholder[10];

        public int Count => _currentIndex + 1;
        public void push(typeholder item) => _items[++_currentIndex] = item;
        public typeholder pop() => _items[_currentIndex--] ;

       
    }

}
