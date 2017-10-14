using System;

namespace ConsoleApp4
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.ReadLine();
            int[] people = Array.ConvertAll(Console.ReadLine().Split(' '), x => int.Parse(x));

            //Get highest
            int highest = 0;
            for (int i = 0; i < people.Length; i++)
            {
                if (people[i] > people[highest])
                    highest = i;
            }

            int allResult = 0;
            while (highest != 0)
            {
                //Flip
                int temp = people[highest - 1];
                people[highest - 1] = people[highest];
                people[highest] = temp;
                allResult++;
                highest--;
            }

            //Get lowest
            int lowest = 0;
            for (int i = 0; i < people.Length; i++)
            {
                if (people[i] <= people[lowest])
                    lowest = i;
            }

            while (people.Length - 1 != lowest)
            {
                    //Flip
                    int temp = people[lowest + 1];
                    people[lowest + 1] = people[lowest];
                    people[lowest] = temp;
                    allResult++;
                lowest++;
            }

            Console.WriteLine(allResult);
            Console.ReadLine();
        }
    }
}