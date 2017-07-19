#!/usr/bin/env python

##
## @brief      Class for the application.
##
class Application(object):
    ##
    ## @brief      Constructs the object.
    ##
    ## @param      self  The object
    ## @param      arg   The argument
    ##
    def __init__(self, arg):
        super(Application, self).__init__()
        self.arg = arg

    ##
    ## @brief      Does a lot of fabulous work
    ##
    ## @param      self    The object
    ## @param      msg     The input message of type ...
    ## @param      source  The client origin
    ##
    ## @return     Returns the input message
    ##
    def my_fabulous_function(self, msg, source):    
        return msg

    def main(self):
        pass
