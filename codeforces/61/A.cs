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
            int[] numbers1 = Array.ConvertAll(Console.ReadLine().ToArray(), x => int.Parse(x.ToString()));
            int[] numbers2 = Array.ConvertAll(Console.ReadLine().ToArray(), x => int.Parse(x.ToString()));
            string result = "";

            for (int i = 0; i < numbers1.Length; i++)
            {
                result += (Convert.ToBoolean(numbers1[i]) ^ Convert.ToBoolean(numbers2[i]) == true ? "1" : "0");
            }

            Console.WriteLine(result);Console.ReadLine();
        }
    }
}
