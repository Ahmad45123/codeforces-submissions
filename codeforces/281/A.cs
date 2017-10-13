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
            var word = Console.ReadLine().ToArray();

            if (Char.IsLower(word[0]))
                word[0] = char.ToUpper(word[0]);

            Console.WriteLine(new string(word));
        }
    }
}
