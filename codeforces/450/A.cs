using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] z = Array.ConvertAll(Console.ReadLine().Split(' '), x => int.Parse(x));
            int[] ppl = Array.ConvertAll(Console.ReadLine().Split(' '), x => int.Parse(x));
            int numberOfPeople = z[0];
            int candiesPerTurn = z[1];
            Queue<Person> queue = new Queue<Person>();

            //Fill data
            for (int i = 1; i <= numberOfPeople; i++)
            {
                queue.Enqueue(new Person(i, ppl[i - 1]));
            }

            int lastChild = 0;

            while (queue.Any())
            {
                if (queue.Count == 1)
                {
                    lastChild = queue.Peek().id;
                }

                Person turn = queue.Dequeue();
                turn.neededCandies -= candiesPerTurn;
                if (turn.neededCandies > 0)
                {
                    queue.Enqueue(turn);
                }
            }

            Console.WriteLine(lastChild);
            Console.Read();
        }

        public struct Person
        {
            public int id;
            public int neededCandies;

            public Person(int i, int candies)
            {
                id = i;
                neededCandies = candies;
            }
        }
    }
}