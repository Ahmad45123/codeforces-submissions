using System;

namespace ConsoleApp4
{
    class Program
    {
        static void Main(string[] args)
        {
            int input = int.Parse(Console.ReadLine());

            if (input % 2 == 1)
            {
                Console.WriteLine(-1);
                return;
            }

            string output = "";
            for (int i = 1; i < input; i+=2)
            {
                output += (i + 1) + " " + i + " ";
            }

            Console.WriteLine(output.Trim());
            Console.ReadLine();
        }
    }
}