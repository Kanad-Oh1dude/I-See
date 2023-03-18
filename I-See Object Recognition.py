''' Object-recognition Module for I-See, I have used a pre-trained Tensorflow model which has been already trained on the COCO dataset  '''

import cv2
from  PIL import Image
from time import sleep
import numpy as np
import RPi.GPIO as GPIO
import time 
import subprocess
from num2words import num2words
from subprocess import call

thres = 0.65 # confidence for recognition.

GPIO.setmode(GPIO.BOARD)
GPIO.setup(12, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup(11, GPIO.IN, pull_up_down=GPIO.PUD_UP)

cap = cv2.VideoCapture(0)

while True:
    
    #GPIO.setup(12, GPIO.IN)
    #GPIO.setup(11, GPIO.IN)
    
    def audio():
        call([cmd_beg+text+cmd_end], shell=True) # used to give speech output from the Raspberry Pi.
    
    def no_audio():
        text1='Turning_Off'
        call([cmd_beg+text1+cmd_end], shell=True) # used to give speech output from the Raspberry Pi.
    input_state = GPIO.input(12) # adding a so that the code turns on when a button is pressed.

    if input_state == False:
        
        cap.set(3, 1280)
        cap.set(4, 720)
        cap.set(10, 70)
        cmd_beg= 'espeak ' # used to give speech output from the Raspberry Pi.
        cmd_end= ' | aplay /home/pi/Desktop/Text.wav  2>/dev/null' # used to give speech output from the Raspberry Pi.
        classNames = []
        classFile = "coco.names" # Class file containing all the names of COCO dataset
        with open(classFile,'rt') as f:
            classNames=[line.rstrip() for line in f]

            configPath = 'ssd_mobilenet_v3_large_coco_2020_01_14.pbtxt' # giving the path to pre-trained model.  
            weightsPath = 'frozen_inference_graph.pb' # giving the path to a frozen file.

            net = cv2.dnn_DetectionModel(weightsPath, configPath) # applying the pre-trained model
            net.setInputSize(320, 320)
            net.setInputScale(1.0 / 127.5)
            net.setInputMean((127.5, 127.5, 127.5))
            net.setInputSwapRB(True)
        
        while True:
            success, img = cap.read()
            classIds, confs, bbox = net.detect(img, confThreshold=thres)
            if len(classIds) != 0:
                for classId, confidence, box in zip(classIds.flatten(), confs.flatten(), bbox):
                    cv2.rectangle(img, box, color=(0, 255, 0), thickness=2) # drawing the rectangle for debugging
                    cv2.putText(img, classNames[classId - 1].upper(), (box[0] + 10, box[1] + 30),
                            cv2.FONT_HERSHEY_COMPLEX, 1, (0, 255, 0), 2)
                    text = classNames[classId - 1] # storing the name of recognised object in text.
                    text = text.replace(' ', '_') # removing the space so that the speech output doesnot break
                    audio()
                    print(text)
                    #exit_state = GPIO.input(11)
                    #print(exit_state)
                    #if exit_state == False:
                    #    break
                        
            exit_state = GPIO.input(11) # adding a so that the code turns off when a button is pressed
            if exit_state == False:
               no_audio()
               break
        
        
cv2.destroyAllWindows()
