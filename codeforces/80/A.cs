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
            int[] number = Array.ConvertAll(Console.ReadLine().Split(' '), x => int.Parse(x));

            //Get next prime number
            int num = number[0];
            while (true)
            {
                num++;
                if(IsPrime(num))
                {
                    break;
                }
            }

            if (num == number[1])
                Console.WriteLine("YES");
            else
                Console.WriteLine("NO");
        }

        public static bool IsPrime(int number)
        {
            if (number == 1) return false;
            if (number == 2) return true;
            if (number % 2 == 0) return false;

            var boundary = (int)Math.Floor(Math.Sqrt(number));

            for (int i = 3; i <= boundary; i += 2)
            {
                if (number % i == 0) return false;
            }

            return true;
        }
    }
}
