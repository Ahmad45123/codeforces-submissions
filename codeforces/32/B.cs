using System;

namespace ConsoleApp4
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = Console.ReadLine();
            string output = "";
            for (int i = 0; i < input.Length; i++)
            {
                if (input[i] == '.')
                    output += "0";

                if (i + 1 < input.Length)
                {
                    if (input[i] == '-' && input[i + 1] == '.')
                    {
                        output += "1";
                        i += 1;
                    }
                    else if (input[i] == '-' && input[i + 1] == '-')
                    {
                        output += "2";
                        i += 1;
                    }
                    
                }
            }
            Console.WriteLine(output);
        }
    }
}
