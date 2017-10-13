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
            string word = Console.ReadLine();

            int capital = 0;
            int small = 0;
            foreach (var c in word)
            {
                if (Char.IsLower(c))
                    small++;
                else
                    capital++;
            }

            if (small >= capital)
                word = word.ToLower();
            else
                word = word.ToUpper();

            Console.WriteLine(word);
        }
    }
}
