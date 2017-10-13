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
            var word = Console.ReadLine();

            int lucky = 0;
            foreach (var c in word)
            {
                if (c == '4')
                    lucky++;
                else if (c == '7')
                    lucky++;
            }

            bool done = true;
            foreach (var c in lucky.ToString())
            {
                if(c != '7' && c != '4')
                {
                    done = false;
                    break;
                }
            }

            if (done)
                Console.WriteLine("YES");
            else
                Console.WriteLine("NO");
        }
    }
}
