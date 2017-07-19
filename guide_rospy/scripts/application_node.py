#!/usr/bin/env python

"""
application_node.py

Launch the application
"""

import rospy

from guide_rospy.application import Application

def main():
    rospy.init_node("application_node_py")
    app = Application()
    app.main()
    rospy.spin()

if __name__ == '__main__':
    main()
