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
import sys
import random

# Die
#
# Description: This class contains the methods for creating a die and is
#             used in creation of the Dice class
#
# Public Methods: Def init
#                 Def roll
#                 Def str
#                

class Die(object):

  #Descript adds sideds to a die
  #
  #Param self, sides
  #
  #Return none
  def __init__(self, sides=None):
    if not sides:
      self.sides = 6
    else:
      if not isinstance(sides, int):
        print("error: sides is not an integer!")
        sys.exit()
      self.sides = sides

  #Descript rolls the die and returns a num in range
  #
  #Param self
  #
  #Return values 
  def roll(self):
    values = [x for x in range(self.sides)]

    random.shuffle(values)

    return values[0] + 1

  #Descript overrides the output
  #
  #Param self, sides
  #
  #Return format for output
  def __str__(self):
    return f"[sides: {self.sides}]"

# Dice
#
# Description: This class is made to implement dice for the dnd program
#              It allows for the creation and use of differnt types of dice
#
# Public Methods: Def init
#                 Def sum
#                 Def max
#                 def min
#                 def avg
#                 def roll
#                 def str
#                

class Dice:

  #Descript adds the num and type of dice
  #
  #Param self, sides, num_dice
  #
  #Return none
  def __init__(self, sides=None, num_dice=1):
    if not sides:
      print("Need to pass in sides!!!")
      sys.exit()
    

    self.sides = sides

    # create a container
    self.dice = []

    for die in range(num_dice):
      self.dice.append(Die(sides))

  def sum(self):
    total = 0
    for d in self.dice:
      total += d.roll()

    return total

  #Descript outputs the max from rolls
  #
  #Param self
  #
  #Return max
  def max(self):
    max = 0
    rolled = 0
    for d in self.dice:
      rolled = d.roll()
      if rolled > max:
        max = rolled

    return max

  #Descript outputs the min from rolls
  #
  #Param self
  #
  #Return min
  def min(self):
    min = 0
    rolled = 0
    for d in self.dice:
      rolled = d.roll()
    if rolled < min:
      min = rolled

    return min

  #Descript outputs the avg from rolls
  #
  #Param self
  #
  #Return avg
  def avg(self):
    avg = 0
    total = 0
    for d in self.dice:
      total += d.roll()
      
    avg = total/d in self.dice
    
    return avg

  #Descript rolls based on the type of roll
  #
  #Param self, rollType
  #
  #Return return self.type
  def roll(self, rollType=None):

    if rollType == 'max':
      return self.max()
    elif rollType == 'min':
      return self.min()
    elif rollType == 'avg':
      return self.avg()
    else:
      return self.sum()

  # def __str__(self):
  #   s = "Dice:[\n"
  #   for d in self.dice:
  #     s = s + f"   [sides: {d.sides}]\n"
  #   s = s+"]\n"
  #   return s

  #Descript overrides the output
  #
  #Param self
  #
  #Return the format of the output
  def __str__(self):
    s = "Dice:[\n    "
    for d in self.dice:
      s = s + str(d)
    s = s + "\n]\n"
    return s
