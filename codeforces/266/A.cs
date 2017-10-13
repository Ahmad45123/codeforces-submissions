using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.ReadLine();
            var word = Console.ReadLine();

            int numberOfChars = 0;
            for (int i = 0; i < word.Length; i++)
            {
                if (i > 0 && word[i - 1] == word[i])
                    numberOfChars++;
            }

            Console.WriteLine(numberOfChars.ToString());
        }
    }
}