using System;
using System.Linq;

namespace ConsoleApp4
{
    class Program
    {
        static void Main(string[] args)
        {
            int times = int.Parse(Console.ReadLine());
            int value = 0;
            for (int j = 0; j < times; j++)
            {
                string qu = Console.ReadLine();
                for (int i = 0; i < qu.Length; i++)
                {
                    //If is plus statement.
                    if (qu[i] == '+' && qu[i + 1] == '+')
                    {
                        value++;
                        i++;
                    }
                    else if (qu[i] == '-' && qu[i + 1] == '-')
                    {
                        value--;
                        i++;
                    }
                }
            }
            Console.WriteLine(value);
            Console.ReadLine();
        }
    }
}