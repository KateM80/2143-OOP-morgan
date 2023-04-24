###############################################################################
 #
 #  Title:            Dice Program
 #  Course:           2143
 #  Semester:         Spring 2023
 #
 #  Description: This program was converted from C++ to python for practice in
 #               using prython. It is used to implement dice for the dnd
 #               program to be made later. It creates a dice class and uses a 
 #               die class.
 #
 #  Usage: Creation of a dice can be done by using the Die function it can then
 #         be used to roll dice and output the dice.           
 #         
 #  Files: main.py
 #         Dice.py
###############################################################################
from Dice import Die
from Dice import Dice


def dieTester(die, runs=10, testType="sum"):
  if isinstance(die, Die):
    print(f"Testing {die.sides} sided die for {runs} rolls:")
    print("    [ ", end="")
    for i in range(runs):
      print(die.roll(), end=" ")
    print("]")
  else:
    print(
      f"Rolling {len(die.dice)} {die.sides} sided die {runs} times to get the {testType} value:"
    )
    print("    [ ", end="")
    for i in range(runs):
      if testType == "avg":
        print(die.avg(), end=" ")
      elif testType == "min":
        print(die.min(), end=" ")
      elif testType == "max":
        print(die.max(), end=" ")
      else:
        print(die.sum(), end=" ")
    print("]")


if __name__ == '__main__':
  d1 = Die()
  d2 = Die(20)
  d3 = Dice(10, 5)

  dieTester(d1, 10)
  dieTester(d2, 20)
  dieTester(d3, 10, "max")
  dieTester(d3, 10, "min")
  dieTester(d3, 10, "avg")