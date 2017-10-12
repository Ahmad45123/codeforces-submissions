using System;

namespace ConsoleApp4
{
    class Program
    {
        static void Main(string[] args)
        {
            int input = int.Parse(Console.ReadLine());
            while (true)
            {
                input++;
                string sin = input.ToString();
                string passed = "";

                bool done = true;
                foreach (char t in sin)
                {
                    if (passed.Contains(t.ToString()))
                    {
                        done = false;
                        break;
                    }

                    passed += t;
                }

                if (done)
                {
                    Console.WriteLine(sin);
                    break;
                }
            }
        }
    }
}
