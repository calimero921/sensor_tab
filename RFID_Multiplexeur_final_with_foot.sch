EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Système de reconnaissance RFID"
Date "2020-07-11"
Rev ""
Comp "DIPONGO ORANGE"
Comment1 "Mohamed EL BOUAZZATI"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L RFID_Multiplexeur_final_with_foot-rescue:HW-178-_Autre-RFID_Multiplexeur-rescue U20
U 1 1 5DE6DFF2
P 7050 4350
F 0 "U20" H 7050 5365 50  0000 C CNN
F 1 "HW-178" H 7050 5274 50  0000 C CNN
F 2 "RFID_Multiplexeur_Kicad_final:HP4067_Demultiplexer" H 7250 5350 50  0001 C CNN
F 3 "" H 7250 5350 50  0001 C CNN
	1    7050 4350
	1    0    0    -1  
$EndComp
$Comp
L RFID_Multiplexeur_final_with_foot-rescue:ESP32_DEV_KIT-_Autre-RFID_Multiplexeur-rescue U30
U 1 1 5DE6E0CE
P 9750 4250
F 0 "U30" H 9750 5415 50  0000 C CNN
F 1 "ESP32_DEV_KIT" H 9750 5324 50  0000 C CNN
F 2 "RFID_Multiplexeur_Kicad_final:ESP32_DEV_KIT" H 10100 5400 50  0001 C CNN
F 3 "" H 10100 5400 50  0001 C CNN
	1    9750 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 2350 2650 2350
Wire Wire Line
	2200 5850 2650 5850
Wire Wire Line
	2200 5150 2650 5150
Connection ~ 2650 5150
Wire Wire Line
	2650 5150 2650 5850
Wire Wire Line
	2200 4450 2650 4450
Wire Wire Line
	2650 2350 2650 3050
Connection ~ 2650 4450
Wire Wire Line
	2650 4450 2650 5150
Wire Wire Line
	2200 3750 2650 3750
Connection ~ 2650 3750
Wire Wire Line
	2650 3750 2650 4450
Wire Wire Line
	2200 3050 2650 3050
Connection ~ 2650 3050
Wire Wire Line
	2650 3050 2650 3750
Wire Wire Line
	2200 1650 2650 1650
Connection ~ 2650 2350
Wire Wire Line
	2200 950  2650 950 
Wire Wire Line
	2650 950  2650 1650
Connection ~ 2650 1650
Wire Wire Line
	2650 1650 2650 2350
Wire Wire Line
	2200 1150 2550 1150
Wire Wire Line
	2550 1150 2550 1250
Wire Wire Line
	2200 6050 2550 6050
Wire Wire Line
	2200 5350 2550 5350
Connection ~ 2550 5350
Wire Wire Line
	2550 5350 2550 6050
Wire Wire Line
	2200 4650 2550 4650
Connection ~ 2550 4650
Wire Wire Line
	2550 4650 2550 5350
Wire Wire Line
	2200 3950 2550 3950
Connection ~ 2550 3950
Wire Wire Line
	2550 3950 2550 4650
Wire Wire Line
	2200 3250 2550 3250
Connection ~ 2550 3250
Wire Wire Line
	2550 3250 2550 3950
Wire Wire Line
	2200 2550 2550 2550
Connection ~ 2550 2550
Wire Wire Line
	2550 2550 2550 3250
Wire Wire Line
	2200 1850 2550 1850
Connection ~ 2550 1850
Wire Wire Line
	2550 1850 2550 2550
Wire Wire Line
	2200 1050 2450 1050
Wire Wire Line
	2450 1050 2450 1100
Wire Wire Line
	2200 5950 2450 5950
Wire Wire Line
	2200 5250 2450 5250
Connection ~ 2450 5250
Wire Wire Line
	2450 5250 2450 5950
Wire Wire Line
	2200 4550 2450 4550
Connection ~ 2450 4550
Wire Wire Line
	2450 4550 2450 5250
Wire Wire Line
	2200 3850 2450 3850
Connection ~ 2450 3850
Wire Wire Line
	2450 3850 2450 4550
Wire Wire Line
	2200 3150 2450 3150
Connection ~ 2450 3150
Wire Wire Line
	2450 3150 2450 3850
Wire Wire Line
	2200 2450 2450 2450
Connection ~ 2450 2450
Wire Wire Line
	2450 2450 2450 3150
Wire Wire Line
	2200 1750 2450 1750
Connection ~ 2450 1750
Wire Wire Line
	2450 1750 2450 2450
Wire Wire Line
	1500 950  1000 950 
Wire Wire Line
	1000 950  1000 1650
Wire Wire Line
	1500 5850 1000 5850
Wire Wire Line
	1500 5150 1000 5150
Connection ~ 1000 5150
Wire Wire Line
	1000 5150 1000 5850
Wire Wire Line
	1500 4450 1000 4450
Connection ~ 1000 4450
Wire Wire Line
	1000 4450 1000 5150
Wire Wire Line
	1500 3750 1000 3750
Connection ~ 1000 3750
Wire Wire Line
	1000 3750 1000 4450
Wire Wire Line
	1500 3050 1000 3050
Connection ~ 1000 3050
Wire Wire Line
	1000 3050 1000 3750
Wire Wire Line
	1500 2350 1000 2350
Connection ~ 1000 2350
Wire Wire Line
	1000 2350 1000 3050
Wire Wire Line
	1500 1650 1000 1650
Connection ~ 1000 1650
Wire Wire Line
	1000 1650 1000 2350
Wire Wire Line
	1500 1050 1100 1050
Wire Wire Line
	1100 1050 1100 1100
Wire Wire Line
	1500 5950 1100 5950
Wire Wire Line
	1500 5250 1100 5250
Connection ~ 1100 5250
Wire Wire Line
	1100 5250 1100 5950
Wire Wire Line
	1500 4550 1100 4550
Connection ~ 1100 4550
Wire Wire Line
	1100 4550 1100 5250
Wire Wire Line
	1500 3850 1100 3850
Connection ~ 1100 3850
Wire Wire Line
	1100 3850 1100 4550
Wire Wire Line
	1500 3150 1100 3150
Connection ~ 1100 3150
Wire Wire Line
	1100 3150 1100 3850
Wire Wire Line
	1500 2450 1100 2450
Connection ~ 1100 2450
Wire Wire Line
	1100 2450 1100 3150
Wire Wire Line
	1500 1750 1100 1750
Connection ~ 1100 1750
Wire Wire Line
	1100 1750 1100 2450
Wire Wire Line
	1500 1150 1200 1150
Wire Wire Line
	1200 1150 1200 1250
Wire Wire Line
	1500 6050 1200 6050
Wire Wire Line
	1500 5350 1200 5350
Connection ~ 1200 5350
Wire Wire Line
	1200 5350 1200 6050
Wire Wire Line
	1500 4650 1200 4650
Connection ~ 1200 4650
Wire Wire Line
	1200 4650 1200 5350
Wire Wire Line
	1500 3950 1200 3950
Connection ~ 1200 3950
Wire Wire Line
	1200 3950 1200 4650
Wire Wire Line
	1500 3250 1200 3250
Connection ~ 1200 3250
Wire Wire Line
	1200 3250 1200 3950
Wire Wire Line
	1500 2550 1200 2550
Connection ~ 1200 2550
Wire Wire Line
	1200 2550 1200 3250
Wire Wire Line
	1500 1850 1200 1850
Connection ~ 1200 1850
Wire Wire Line
	1200 1850 1200 2550
Text GLabel 1500 1250 0    50   Input ~ 0
SDA1
Text GLabel 1500 1950 0    50   Input ~ 0
SDA2
Text GLabel 1500 2650 0    50   Input ~ 0
SDA3
Text GLabel 1500 3350 0    50   Input ~ 0
SDA4
Text GLabel 1500 4050 0    50   Input ~ 0
SDA5
Text GLabel 1500 4750 0    50   Input ~ 0
SDA6
Text GLabel 1500 5450 0    50   Input ~ 0
SDA7
Text GLabel 1500 6150 0    50   Input ~ 0
SDA8
Text GLabel 850  950  0    50   Input ~ 0
MISO
Wire Wire Line
	1000 950  850  950 
Connection ~ 1000 950 
Text GLabel 850  1100 0    50   Input ~ 0
MOSI
Wire Wire Line
	1100 1100 850  1100
Connection ~ 1100 1100
Wire Wire Line
	1100 1100 1100 1750
Text GLabel 850  1250 0    50   Input ~ 0
SCK
Wire Wire Line
	850  1250 1200 1250
Connection ~ 1200 1250
Wire Wire Line
	1200 1250 1200 1850
Text GLabel 2800 1100 2    50   Input ~ 0
RST
Wire Wire Line
	2800 950  2650 950 
Connection ~ 2650 950 
Wire Wire Line
	2800 1100 2450 1100
Connection ~ 2450 1100
Wire Wire Line
	2450 1100 2450 1750
Wire Wire Line
	2800 1250 2550 1250
Connection ~ 2550 1250
Wire Wire Line
	2550 1250 2550 1850
$Comp
L power:GND #PWR0101
U 1 1 5E04C531
P 2800 1350
F 0 "#PWR0101" H 2800 1100 50  0001 C CNN
F 1 "GND" H 2805 1177 50  0000 C CNN
F 2 "" H 2800 1350 50  0001 C CNN
F 3 "" H 2800 1350 50  0001 C CNN
	1    2800 1350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5E04C641
P 9850 1400
F 0 "#PWR0102" H 9850 1150 50  0001 C CNN
F 1 "GND" H 9855 1227 50  0000 C CNN
F 2 "" H 9850 1400 50  0001 C CNN
F 3 "" H 9850 1400 50  0001 C CNN
	1    9850 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	9750 1200 9750 1300
Wire Wire Line
	9950 1200 9950 1300
Wire Wire Line
	9750 1300 9850 1300
Wire Wire Line
	9850 1400 9850 1300
Connection ~ 9850 1300
Wire Wire Line
	9850 1300 9950 1300
$Comp
L Connector:Conn_01x02_Male J60
U 1 1 5E05C961
P 7350 2050
F 0 "J60" H 7456 2228 50  0000 C CNN
F 1 "Conn_01x02_Male" H 7456 2137 50  0000 C CNN
F 2 "TerminalBlock:TerminalBlock_bornier-2_P5.08mm" H 7350 2050 50  0001 C CNN
F 3 "~" H 7350 2050 50  0001 C CNN
	1    7350 2050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 5E060B6B
P 7850 1950
F 0 "#PWR0104" H 7850 1700 50  0001 C CNN
F 1 "GND" H 7855 1777 50  0000 C CNN
F 2 "" H 7850 1950 50  0001 C CNN
F 3 "" H 7850 1950 50  0001 C CNN
	1    7850 1950
	1    0    0    1   
$EndComp
Wire Wire Line
	7550 2050 7850 2050
Wire Wire Line
	7850 2050 7850 1950
$Comp
L power:+5V #PWR0105
U 1 1 5E075CE4
P 9400 850
F 0 "#PWR0105" H 9400 700 50  0001 C CNN
F 1 "+5V" H 9415 1023 50  0000 C CNN
F 2 "" H 9400 850 50  0001 C CNN
F 3 "" H 9400 850 50  0001 C CNN
	1    9400 850 
	1    0    0    -1  
$EndComp
Wire Wire Line
	9550 900  9400 900 
Wire Wire Line
	9400 900  9400 850 
$Comp
L power:+3V3 #PWR0106
U 1 1 5E07EB88
P 2800 850
F 0 "#PWR0106" H 2800 700 50  0001 C CNN
F 1 "+3V3" H 2815 1023 50  0000 C CNN
F 2 "" H 2800 850 50  0001 C CNN
F 3 "" H 2800 850 50  0001 C CNN
	1    2800 850 
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 850  2800 950 
Wire Wire Line
	2800 1250 2800 1350
$Comp
L power:+3V3 #PWR0107
U 1 1 5E087AEA
P 10350 800
F 0 "#PWR0107" H 10350 650 50  0001 C CNN
F 1 "+3V3" H 10365 973 50  0000 C CNN
F 2 "" H 10350 800 50  0001 C CNN
F 3 "" H 10350 800 50  0001 C CNN
	1    10350 800 
	1    0    0    -1  
$EndComp
Wire Wire Line
	10150 900  10350 900 
Wire Wire Line
	10350 900  10350 800 
Text GLabel 6650 5100 0    50   Input ~ 0
SDA1
Text GLabel 6650 5000 0    50   Input ~ 0
SDA2
Text GLabel 6650 4900 0    50   Input ~ 0
SDA3
Text GLabel 6650 4800 0    50   Input ~ 0
SDA4
Text GLabel 6650 4700 0    50   Input ~ 0
SDA5
Text GLabel 6650 4600 0    50   Input ~ 0
SDA6
Text GLabel 6650 4500 0    50   Input ~ 0
SDA7
Text GLabel 6650 4400 0    50   Input ~ 0
SDA8
Text GLabel 6650 4300 0    50   Input ~ 0
SDA9
Wire Wire Line
	6700 4300 6650 4300
Wire Wire Line
	6700 4400 6650 4400
Wire Wire Line
	6700 4500 6650 4500
Wire Wire Line
	6700 4600 6650 4600
Wire Wire Line
	6700 4700 6650 4700
Wire Wire Line
	6700 4800 6650 4800
Wire Wire Line
	6700 4900 6650 4900
Wire Wire Line
	6700 5000 6650 5000
Wire Wire Line
	6700 5100 6650 5100
$Comp
L power:+5V #PWR0112
U 1 1 5E22D643
P 9300 5500
F 0 "#PWR0112" H 9300 5350 50  0001 C CNN
F 1 "+5V" H 9315 5673 50  0000 C CNN
F 2 "" H 9300 5500 50  0001 C CNN
F 3 "" H 9300 5500 50  0001 C CNN
	1    9300 5500
	1    0    0    -1  
$EndComp
Wire Wire Line
	9300 5500 9300 5550
Wire Wire Line
	7400 4800 7550 4800
Wire Wire Line
	7550 4800 7550 5000
Wire Wire Line
	7550 5000 7400 5000
Wire Wire Line
	7550 5000 7550 5100
Connection ~ 7550 5000
$Comp
L power:GND #PWR0113
U 1 1 5E276D13
P 7550 5100
F 0 "#PWR0113" H 7550 4850 50  0001 C CNN
F 1 "GND" H 7555 4927 50  0000 C CNN
F 2 "" H 7550 5100 50  0001 C CNN
F 3 "" H 7550 5100 50  0001 C CNN
	1    7550 5100
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0114
U 1 1 5E276E3E
P 7750 4850
F 0 "#PWR0114" H 7750 4700 50  0001 C CNN
F 1 "+3V3" H 7765 5023 50  0000 C CNN
F 2 "" H 7750 4850 50  0001 C CNN
F 3 "" H 7750 4850 50  0001 C CNN
	1    7750 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	7400 4900 7750 4900
Wire Wire Line
	7750 4900 7750 4850
Text GLabel 10350 4150 2    50   Input ~ 0
SCK
Wire Wire Line
	10350 4150 10250 4150
Text GLabel 10350 3450 2    50   Input ~ 0
MOSI
Wire Wire Line
	10350 3450 10250 3450
Text GLabel 10350 4050 2    50   Input ~ 0
MISO
Wire Wire Line
	10350 4050 10250 4050
Text GLabel 10350 3550 2    50   Input ~ 0
RST
Wire Wire Line
	10350 3550 10250 3550
$Comp
L power:GND #PWR0115
U 1 1 5E31859E
P 10400 3250
F 0 "#PWR0115" H 10400 3000 50  0001 C CNN
F 1 "GND" H 10405 3077 50  0000 C CNN
F 2 "" H 10400 3250 50  0001 C CNN
F 3 "" H 10400 3250 50  0001 C CNN
	1    10400 3250
	1    0    0    1   
$EndComp
Wire Wire Line
	10250 3350 10400 3350
Wire Wire Line
	10400 3350 10400 3250
Text GLabel 10350 4350 2    50   Input ~ 0
DIn
Wire Wire Line
	10250 4350 10350 4350
Wire Wire Line
	9250 5150 9200 5150
Wire Wire Line
	9200 5150 9200 5550
Wire Wire Line
	9200 5550 9300 5550
$Comp
L Device:C C10
U 1 1 5E1D0BB6
P 9200 5800
F 0 "C10" H 9315 5846 50  0000 L CNN
F 1 "C" H 9315 5755 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D10.0mm_P5.00mm" H 9238 5650 50  0001 C CNN
F 3 "~" H 9200 5800 50  0001 C CNN
	1    9200 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	9200 5650 9200 5550
Connection ~ 9200 5550
Wire Wire Line
	9200 5950 9200 6050
$Comp
L power:GND #PWR0109
U 1 1 5E1F6BF8
P 9200 6050
F 0 "#PWR0109" H 9200 5800 50  0001 C CNN
F 1 "GND" H 9205 5877 50  0000 C CNN
F 2 "" H 9200 6050 50  0001 C CNN
F 3 "" H 9200 6050 50  0001 C CNN
	1    9200 6050
	1    0    0    -1  
$EndComp
$Comp
L Device:C C40
U 1 1 5E20AD97
P 10350 1150
F 0 "C40" H 10465 1196 50  0000 L CNN
F 1 "C" H 10465 1105 50  0000 L CNN
F 2 "RFID_Multiplexeur_Kicad_final:CP_220uF_Eirbot" H 10388 1000 50  0001 C CNN
F 3 "~" H 10350 1150 50  0001 C CNN
	1    10350 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	10350 1000 10350 900 
Wire Wire Line
	10350 1300 10350 1400
$Comp
L power:GND #PWR0111
U 1 1 5E20ADA0
P 10350 1400
F 0 "#PWR0111" H 10350 1150 50  0001 C CNN
F 1 "GND" H 10355 1227 50  0000 C CNN
F 2 "" H 10350 1400 50  0001 C CNN
F 3 "" H 10350 1400 50  0001 C CNN
	1    10350 1400
	1    0    0    -1  
$EndComp
$Comp
L Device:C C41
U 1 1 5E214EE8
P 9400 1150
F 0 "C41" H 9515 1196 50  0000 L CNN
F 1 "C" H 9515 1105 50  0000 L CNN
F 2 "RFID_Multiplexeur_Kicad_final:CP_220uF_Eirbot" H 9438 1000 50  0001 C CNN
F 3 "~" H 9400 1150 50  0001 C CNN
	1    9400 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	9400 1000 9400 900 
Wire Wire Line
	9400 1300 9400 1400
$Comp
L power:GND #PWR0118
U 1 1 5E214EF1
P 9400 1400
F 0 "#PWR0118" H 9400 1150 50  0001 C CNN
F 1 "GND" H 9405 1227 50  0000 C CNN
F 2 "" H 9400 1400 50  0001 C CNN
F 3 "" H 9400 1400 50  0001 C CNN
	1    9400 1400
	1    0    0    -1  
$EndComp
$Comp
L Device:C C51
U 1 1 5E21F5F1
P 3150 1250
F 0 "C51" H 3265 1296 50  0000 L CNN
F 1 "C" H 3265 1205 50  0000 L CNN
F 2 "RFID_Multiplexeur_Kicad_final:CP_220uF_Eirbot" H 3188 1100 50  0001 C CNN
F 3 "~" H 3150 1250 50  0001 C CNN
	1    3150 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3150 1400 3150 1500
$Comp
L power:GND #PWR0119
U 1 1 5E21F5FA
P 3150 1500
F 0 "#PWR0119" H 3150 1250 50  0001 C CNN
F 1 "GND" H 3155 1327 50  0000 C CNN
F 2 "" H 3150 1500 50  0001 C CNN
F 3 "" H 3150 1500 50  0001 C CNN
	1    3150 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 950  3150 950 
Wire Wire Line
	3150 950  3150 1100
Connection ~ 2800 950 
$Comp
L Device:C C20
U 1 1 5E234D12
P 7750 5150
F 0 "C20" H 7865 5196 50  0000 L CNN
F 1 "C" H 7865 5105 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D10.0mm_P5.00mm" H 7788 5000 50  0001 C CNN
F 3 "~" H 7750 5150 50  0001 C CNN
	1    7750 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	7750 5000 7750 4900
Wire Wire Line
	7750 5300 7750 5400
$Comp
L power:GND #PWR0120
U 1 1 5E234D1B
P 7750 5400
F 0 "#PWR0120" H 7750 5150 50  0001 C CNN
F 1 "GND" H 7755 5227 50  0000 C CNN
F 2 "" H 7750 5400 50  0001 C CNN
F 3 "" H 7750 5400 50  0001 C CNN
	1    7750 5400
	1    0    0    -1  
$EndComp
Connection ~ 9400 900 
Connection ~ 10350 900 
Connection ~ 7750 4900
Connection ~ 6800 1050
Wire Wire Line
	6800 1050 6450 1050
$Comp
L power:GND #PWR0110
U 1 1 5E1F7046
P 6450 1550
F 0 "#PWR0110" H 6450 1300 50  0001 C CNN
F 1 "GND" H 6455 1377 50  0000 C CNN
F 2 "" H 6450 1550 50  0001 C CNN
F 3 "" H 6450 1550 50  0001 C CNN
	1    6450 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	6450 1450 6450 1550
Wire Wire Line
	6450 1150 6450 1050
$Comp
L Device:C C71
U 1 1 5E1F703D
P 6450 1300
F 0 "C71" H 6565 1346 50  0000 L CNN
F 1 "C" H 6565 1255 50  0000 L CNN
F 2 "RFID_Multiplexeur_Kicad_final:CP_Radial_D10.0mm_P5.00mm" H 6488 1150 50  0001 C CNN
F 3 "~" H 6450 1300 50  0001 C CNN
	1    6450 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	7100 1250 7200 1250
Text GLabel 7100 1250 0    50   Input ~ 0
DIn
Wire Wire Line
	6800 1050 6800 1000
Wire Wire Line
	7200 1050 6800 1050
$Comp
L power:+5V #PWR0117
U 1 1 5DF16A7B
P 6800 1000
F 0 "#PWR0117" H 6800 850 50  0001 C CNN
F 1 "+5V" H 6815 1173 50  0000 C CNN
F 2 "" H 6800 1000 50  0001 C CNN
F 3 "" H 6800 1000 50  0001 C CNN
	1    6800 1000
	-1   0    0    -1  
$EndComp
Wire Wire Line
	6800 1150 6800 1200
Wire Wire Line
	7200 1150 6800 1150
$Comp
L power:GND #PWR0116
U 1 1 5DEE317F
P 6800 1200
F 0 "#PWR0116" H 6800 950 50  0001 C CNN
F 1 "GND" H 6805 1027 50  0000 C CNN
F 2 "" H 6800 1200 50  0001 C CNN
F 3 "" H 6800 1200 50  0001 C CNN
	1    6800 1200
	-1   0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x03_Male J70
U 1 1 5DEE2E7C
P 7400 1150
F 0 "J70" H 7500 1550 50  0000 C CNN
F 1 "Conn_01x03_Male" H 7450 1400 50  0000 C CNN
F 2 "Connector_JST:JST_PH_S3B-PH-K_1x03_P2.00mm_Horizontal" H 7400 1150 50  0001 C CNN
F 3 "~" H 7400 1150 50  0001 C CNN
	1    7400 1150
	-1   0    0    -1  
$EndComp
Text GLabel 6650 4200 0    50   Input ~ 0
SDA10
Text GLabel 6650 4100 0    50   Input ~ 0
SDA11
Text GLabel 6650 4000 0    50   Input ~ 0
SDA12
Wire Wire Line
	6700 4000 6650 4000
Wire Wire Line
	6700 4100 6650 4100
Wire Wire Line
	6700 4200 6650 4200
Text GLabel 6650 3900 0    50   Input ~ 0
SDA13
Text GLabel 6650 3800 0    50   Input ~ 0
SDA14
Text GLabel 6650 3700 0    50   Input ~ 0
SDA15
Wire Wire Line
	6700 3700 6650 3700
Wire Wire Line
	6700 3800 6650 3800
Wire Wire Line
	6700 3900 6650 3900
Text GLabel 6650 3600 0    50   Input ~ 0
SDA16
Wire Wire Line
	6700 3600 6650 3600
Wire Wire Line
	5200 2300 5650 2300
Wire Wire Line
	5200 5100 5650 5100
Connection ~ 5650 5100
Wire Wire Line
	5650 5100 5650 5800
Wire Wire Line
	5200 4400 5650 4400
Wire Wire Line
	5650 2300 5650 3000
Connection ~ 5650 4400
Wire Wire Line
	5650 4400 5650 5100
Wire Wire Line
	5200 3700 5650 3700
Connection ~ 5650 3700
Wire Wire Line
	5650 3700 5650 4400
Wire Wire Line
	5200 3000 5650 3000
Connection ~ 5650 3000
Wire Wire Line
	5650 3000 5650 3700
Wire Wire Line
	5200 1600 5650 1600
Connection ~ 5650 2300
Wire Wire Line
	5200 900  5650 900 
Wire Wire Line
	5650 900  5650 1600
Connection ~ 5650 1600
Wire Wire Line
	5650 1600 5650 2300
Wire Wire Line
	5200 1100 5550 1100
Wire Wire Line
	5550 1100 5550 1200
Wire Wire Line
	5200 5300 5550 5300
Connection ~ 5550 5300
Wire Wire Line
	5550 5300 5550 6000
Wire Wire Line
	5200 4600 5550 4600
Connection ~ 5550 4600
Wire Wire Line
	5550 4600 5550 5300
Wire Wire Line
	5200 3900 5550 3900
Connection ~ 5550 3900
Wire Wire Line
	5550 3900 5550 4600
Wire Wire Line
	5200 3200 5550 3200
Connection ~ 5550 3200
Wire Wire Line
	5550 3200 5550 3900
Wire Wire Line
	5200 2500 5550 2500
Connection ~ 5550 2500
Wire Wire Line
	5550 2500 5550 3200
Wire Wire Line
	5200 1800 5550 1800
Connection ~ 5550 1800
Wire Wire Line
	5550 1800 5550 2500
Wire Wire Line
	5200 1000 5450 1000
Wire Wire Line
	5450 1000 5450 1050
Wire Wire Line
	5200 5200 5450 5200
Connection ~ 5450 5200
Wire Wire Line
	5450 5200 5450 5900
Wire Wire Line
	5200 4500 5450 4500
Connection ~ 5450 4500
Wire Wire Line
	5450 4500 5450 5200
Wire Wire Line
	5200 3800 5450 3800
Connection ~ 5450 3800
Wire Wire Line
	5450 3800 5450 4500
Wire Wire Line
	5200 3100 5450 3100
Connection ~ 5450 3100
Wire Wire Line
	5450 3100 5450 3800
Wire Wire Line
	5200 2400 5450 2400
Connection ~ 5450 2400
Wire Wire Line
	5450 2400 5450 3100
Wire Wire Line
	5200 1700 5450 1700
Connection ~ 5450 1700
Wire Wire Line
	5450 1700 5450 2400
Wire Wire Line
	4500 900  4000 900 
Wire Wire Line
	4000 900  4000 1600
Wire Wire Line
	4500 5100 4000 5100
Connection ~ 4000 5100
Wire Wire Line
	4000 5100 4000 5800
Wire Wire Line
	4500 4400 4000 4400
Connection ~ 4000 4400
Wire Wire Line
	4000 4400 4000 5100
Wire Wire Line
	4500 3700 4000 3700
Connection ~ 4000 3700
Wire Wire Line
	4000 3700 4000 4400
Wire Wire Line
	4500 3000 4000 3000
Connection ~ 4000 3000
Wire Wire Line
	4000 3000 4000 3700
Wire Wire Line
	4500 2300 4000 2300
Connection ~ 4000 2300
Wire Wire Line
	4000 2300 4000 3000
Wire Wire Line
	4500 1600 4000 1600
Connection ~ 4000 1600
Wire Wire Line
	4000 1600 4000 2300
Wire Wire Line
	4500 1000 4100 1000
Wire Wire Line
	4100 1000 4100 1050
Wire Wire Line
	4500 5200 4100 5200
Connection ~ 4100 5200
Wire Wire Line
	4100 5200 4100 5900
Wire Wire Line
	4500 4500 4100 4500
Connection ~ 4100 4500
Wire Wire Line
	4100 4500 4100 5200
Wire Wire Line
	4500 3800 4100 3800
Connection ~ 4100 3800
Wire Wire Line
	4100 3800 4100 4500
Wire Wire Line
	4500 3100 4100 3100
Connection ~ 4100 3100
Wire Wire Line
	4100 3100 4100 3800
Wire Wire Line
	4500 2400 4100 2400
Connection ~ 4100 2400
Wire Wire Line
	4100 2400 4100 3100
Wire Wire Line
	4500 1700 4100 1700
Connection ~ 4100 1700
Wire Wire Line
	4100 1700 4100 2400
Wire Wire Line
	4500 1100 4200 1100
Wire Wire Line
	4200 1100 4200 1200
Wire Wire Line
	4500 5300 4200 5300
Connection ~ 4200 5300
Wire Wire Line
	4200 5300 4200 6000
Wire Wire Line
	4500 4600 4200 4600
Connection ~ 4200 4600
Wire Wire Line
	4200 4600 4200 5300
Wire Wire Line
	4500 3900 4200 3900
Connection ~ 4200 3900
Wire Wire Line
	4200 3900 4200 4600
Wire Wire Line
	4500 3200 4200 3200
Connection ~ 4200 3200
Wire Wire Line
	4200 3200 4200 3900
Wire Wire Line
	4500 2500 4200 2500
Connection ~ 4200 2500
Wire Wire Line
	4200 2500 4200 3200
Wire Wire Line
	4500 1800 4200 1800
Connection ~ 4200 1800
Wire Wire Line
	4200 1800 4200 2500
Text GLabel 4500 1200 0    50   Input ~ 0
SDA16
Text GLabel 4500 1900 0    50   Input ~ 0
SDA15
Text GLabel 4500 2600 0    50   Input ~ 0
SDA14
Text GLabel 4500 3300 0    50   Input ~ 0
SDA13
Text GLabel 4500 4000 0    50   Input ~ 0
SDA12
Text GLabel 4500 4700 0    50   Input ~ 0
SDA11
Text GLabel 4500 5400 0    50   Input ~ 0
SDA10
Text GLabel 3850 900  0    50   Input ~ 0
MISO
Wire Wire Line
	4000 900  3850 900 
Connection ~ 4000 900 
Text GLabel 3850 1050 0    50   Input ~ 0
MOSI
Wire Wire Line
	4100 1050 3850 1050
Connection ~ 4100 1050
Wire Wire Line
	4100 1050 4100 1700
Text GLabel 3850 1200 0    50   Input ~ 0
SCK
Wire Wire Line
	3850 1200 4200 1200
Connection ~ 4200 1200
Wire Wire Line
	4200 1200 4200 1800
Text GLabel 5800 1050 2    50   Input ~ 0
RST
Wire Wire Line
	5800 1050 5450 1050
Connection ~ 5450 1050
Wire Wire Line
	5450 1050 5450 1700
Wire Wire Line
	5800 1200 5550 1200
Connection ~ 5550 1200
Wire Wire Line
	5550 1200 5550 1800
$Comp
L power:GND #PWR0121
U 1 1 5F2052BB
P 5800 1300
F 0 "#PWR0121" H 5800 1050 50  0001 C CNN
F 1 "GND" H 5805 1127 50  0000 C CNN
F 2 "" H 5800 1300 50  0001 C CNN
F 3 "" H 5800 1300 50  0001 C CNN
	1    5800 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 1200 5800 1300
Wire Wire Line
	5650 900  5650 600 
Wire Wire Line
	5650 600  2650 600 
Wire Wire Line
	2650 600  2650 950 
Connection ~ 5650 900 
Wire Wire Line
	5200 5800 5650 5800
Wire Wire Line
	5200 6000 5550 6000
Wire Wire Line
	5200 5900 5450 5900
Wire Wire Line
	4500 6000 4200 6000
Wire Wire Line
	4500 5900 4100 5900
Wire Wire Line
	4500 5800 4000 5800
Text GLabel 4500 6100 0    50   Input ~ 0
SDA9
Wire Wire Line
	1500 7150 1500 7050
Wire Wire Line
	1750 7150 1750 7050
Wire Wire Line
	2000 7150 2000 7050
Wire Wire Line
	2250 7150 2250 7050
Wire Wire Line
	2500 7150 2500 7050
Wire Wire Line
	2750 7150 2750 7050
Wire Wire Line
	3000 7050 3000 7150
Wire Wire Line
	2750 6500 2750 6650
$Comp
L power:+3V3 #PWR0108
U 1 1 5E0B6BE7
P 2750 6500
F 0 "#PWR0108" H 2750 6350 50  0001 C CNN
F 1 "+3V3" H 2765 6673 50  0000 C CNN
F 2 "" H 2750 6500 50  0001 C CNN
F 3 "" H 2750 6500 50  0001 C CNN
	1    2750 6500
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 6650 1750 6650
Wire Wire Line
	1500 6750 1500 6650
Wire Wire Line
	1750 6650 2000 6650
Connection ~ 1750 6650
Wire Wire Line
	1750 6750 1750 6650
Wire Wire Line
	2000 6650 2250 6650
Connection ~ 2000 6650
Wire Wire Line
	2000 6750 2000 6650
Wire Wire Line
	2250 6650 2500 6650
Connection ~ 2250 6650
Wire Wire Line
	2250 6750 2250 6650
Wire Wire Line
	2500 6650 2750 6650
Connection ~ 2500 6650
Wire Wire Line
	2500 6750 2500 6650
Wire Wire Line
	2750 6650 3000 6650
Connection ~ 2750 6650
Wire Wire Line
	2750 6750 2750 6650
Wire Wire Line
	3000 6650 3000 6750
Text GLabel 1500 7150 3    50   Input ~ 0
SDA16
Text GLabel 1750 7150 3    50   Input ~ 0
SDA15
Text GLabel 2000 7150 3    50   Input ~ 0
SDA14
Text GLabel 2250 7150 3    50   Input ~ 0
SDA13
Text GLabel 2500 7150 3    50   Input ~ 0
SDA12
Text GLabel 2750 7150 3    50   Input ~ 0
SDA11
Text GLabel 3000 7150 3    50   Input ~ 0
SDA10
$Comp
L Device:R R11
U 1 1 5DFA7BDE
P 2750 6900
F 0 "R11" H 2820 6946 50  0000 L CNN
F 1 "R" H 2820 6855 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 2680 6900 50  0001 C CNN
F 3 "~" H 2750 6900 50  0001 C CNN
	1    2750 6900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R10
U 1 1 5DFA7BD7
P 3000 6900
F 0 "R10" H 3070 6946 50  0000 L CNN
F 1 "R" H 3070 6855 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 2930 6900 50  0001 C CNN
F 3 "~" H 3000 6900 50  0001 C CNN
	1    3000 6900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R13
U 1 1 5DFA7BD0
P 2250 6900
F 0 "R13" H 2320 6946 50  0000 L CNN
F 1 "R" H 2320 6855 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 2180 6900 50  0001 C CNN
F 3 "~" H 2250 6900 50  0001 C CNN
	1    2250 6900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R12
U 1 1 5DFA7BC9
P 2500 6900
F 0 "R12" H 2570 6946 50  0000 L CNN
F 1 "R" H 2570 6855 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 2430 6900 50  0001 C CNN
F 3 "~" H 2500 6900 50  0001 C CNN
	1    2500 6900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R15
U 1 1 5DF9E466
P 1750 6900
F 0 "R15" H 1820 6946 50  0000 L CNN
F 1 "R" H 1820 6855 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 1680 6900 50  0001 C CNN
F 3 "~" H 1750 6900 50  0001 C CNN
	1    1750 6900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R14
U 1 1 5DF9E45F
P 2000 6900
F 0 "R14" H 2070 6946 50  0000 L CNN
F 1 "R" H 2070 6855 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 1930 6900 50  0001 C CNN
F 3 "~" H 2000 6900 50  0001 C CNN
	1    2000 6900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R16
U 1 1 5DF94C5B
P 1500 6900
F 0 "R16" H 1570 6946 50  0000 L CNN
F 1 "R" H 1570 6855 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 1430 6900 50  0001 C CNN
F 3 "~" H 1500 6900 50  0001 C CNN
	1    1500 6900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 7150 3300 7050
Wire Wire Line
	3550 7150 3550 7050
Wire Wire Line
	3800 7150 3800 7050
Wire Wire Line
	4050 7150 4050 7050
Wire Wire Line
	4300 7150 4300 7050
Wire Wire Line
	4550 7150 4550 7050
Wire Wire Line
	4800 7150 4800 7050
Wire Wire Line
	5050 7150 5050 7050
Wire Wire Line
	5300 7050 5300 7150
Wire Wire Line
	3550 6650 3800 6650
Connection ~ 3550 6650
Wire Wire Line
	3550 6650 3550 6750
Wire Wire Line
	3800 6650 4050 6650
Connection ~ 3800 6650
Wire Wire Line
	3800 6750 3800 6650
Wire Wire Line
	4050 6650 4300 6650
Connection ~ 4050 6650
Wire Wire Line
	4050 6750 4050 6650
Wire Wire Line
	4300 6650 4550 6650
Connection ~ 4300 6650
Wire Wire Line
	4300 6750 4300 6650
Wire Wire Line
	4550 6650 4800 6650
Connection ~ 4550 6650
Wire Wire Line
	4550 6750 4550 6650
Wire Wire Line
	4800 6650 5050 6650
Connection ~ 4800 6650
Wire Wire Line
	4800 6750 4800 6650
Wire Wire Line
	5050 6650 5300 6650
Connection ~ 5050 6650
Wire Wire Line
	5050 6750 5050 6650
Wire Wire Line
	5300 6650 5300 6750
Wire Wire Line
	3300 6650 3550 6650
Wire Wire Line
	3300 6750 3300 6650
Text GLabel 3300 7150 3    50   Input ~ 0
SDA9
Text GLabel 3550 7150 3    50   Input ~ 0
SDA8
Text GLabel 3800 7150 3    50   Input ~ 0
SDA7
Text GLabel 4050 7150 3    50   Input ~ 0
SDA6
Text GLabel 4300 7150 3    50   Input ~ 0
SDA5
Text GLabel 4550 7150 3    50   Input ~ 0
SDA4
Text GLabel 4800 7150 3    50   Input ~ 0
SDA3
Text GLabel 5050 7150 3    50   Input ~ 0
SDA2
Text GLabel 5300 7150 3    50   Input ~ 0
SDA1
$Comp
L Device:R R9
U 1 1 5F31421D
P 3300 6900
F 0 "R9" H 3370 6946 50  0000 L CNN
F 1 "R" H 3370 6855 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 3230 6900 50  0001 C CNN
F 3 "~" H 3300 6900 50  0001 C CNN
	1    3300 6900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 5F314223
P 5050 6900
F 0 "R2" H 5120 6946 50  0000 L CNN
F 1 "R" H 5120 6855 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 4980 6900 50  0001 C CNN
F 3 "~" H 5050 6900 50  0001 C CNN
	1    5050 6900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5F314229
P 5300 6900
F 0 "R1" H 5370 6946 50  0000 L CNN
F 1 "R" H 5370 6855 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 5230 6900 50  0001 C CNN
F 3 "~" H 5300 6900 50  0001 C CNN
	1    5300 6900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 5F31422F
P 4550 6900
F 0 "R4" H 4620 6946 50  0000 L CNN
F 1 "R" H 4620 6855 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 4480 6900 50  0001 C CNN
F 3 "~" H 4550 6900 50  0001 C CNN
	1    4550 6900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 5F314235
P 4800 6900
F 0 "R3" H 4870 6946 50  0000 L CNN
F 1 "R" H 4870 6855 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 4730 6900 50  0001 C CNN
F 3 "~" H 4800 6900 50  0001 C CNN
	1    4800 6900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 5F31423B
P 4050 6900
F 0 "R6" H 4120 6946 50  0000 L CNN
F 1 "R" H 4120 6855 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 3980 6900 50  0001 C CNN
F 3 "~" H 4050 6900 50  0001 C CNN
	1    4050 6900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R5
U 1 1 5F314241
P 4300 6900
F 0 "R5" H 4370 6946 50  0000 L CNN
F 1 "R" H 4370 6855 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 4230 6900 50  0001 C CNN
F 3 "~" H 4300 6900 50  0001 C CNN
	1    4300 6900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R8
U 1 1 5F314247
P 3550 6900
F 0 "R8" H 3620 6946 50  0000 L CNN
F 1 "R" H 3620 6855 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 3480 6900 50  0001 C CNN
F 3 "~" H 3550 6900 50  0001 C CNN
	1    3550 6900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R7
U 1 1 5F31424D
P 3800 6900
F 0 "R7" H 3870 6946 50  0000 L CNN
F 1 "R" H 3870 6855 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 3730 6900 50  0001 C CNN
F 3 "~" H 3800 6900 50  0001 C CNN
	1    3800 6900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 6650 3000 6650
Connection ~ 3300 6650
Connection ~ 3000 6650
Text GLabel 10350 3850 2    50   Input ~ 0
SDA
Wire Wire Line
	10250 3850 10350 3850
Wire Wire Line
	7400 3900 7500 3900
Text GLabel 7500 3900 2    50   Input ~ 0
SDA
Wire Wire Line
	7400 4250 7500 4250
Text GLabel 7500 4250 2    50   Input ~ 0
MUX3
Wire Wire Line
	7400 4350 7500 4350
Text GLabel 7500 4350 2    50   Input ~ 0
MUX2
Wire Wire Line
	7400 4450 7500 4450
Text GLabel 7500 4450 2    50   Input ~ 0
MUX1
Wire Wire Line
	7400 4550 7500 4550
Text GLabel 7500 4550 2    50   Input ~ 0
MUX0
Wire Wire Line
	10250 4850 10350 4850
Text GLabel 10350 4850 2    50   Input ~ 0
MUX3
Wire Wire Line
	9250 4750 9150 4750
Text GLabel 9150 4750 0    50   Input ~ 0
MUX1
Wire Wire Line
	9250 4550 9150 4550
Text GLabel 9150 4550 0    50   Input ~ 0
MUX0
Wire Wire Line
	9250 4450 9150 4450
Text GLabel 9150 4450 0    50   Input ~ 0
MUX2
$Comp
L RFID_Multiplexeur-cache:RF_RFID_RC522 U1
U 1 1 5F09C22F
P 1850 1150
F 0 "U1" H 1850 1615 50  0000 C CNN
F 1 "RF_RFID_RC522" H 1850 1524 50  0000 C CNN
F 2 "Connector_JST:JST_PH_B8B-PH-SM4-TB_1x08-1MP_P2.00mm_Vertical" H 2000 1600 50  0001 C CNN
F 3 "" H 2000 1600 50  0001 C CNN
	1    1850 1150
	1    0    0    -1  
$EndComp
$Comp
L RFID_Multiplexeur-cache:RF_RFID_RC522 U2
U 1 1 5F09E408
P 1850 1850
F 0 "U2" H 1850 2315 50  0000 C CNN
F 1 "RF_RFID_RC522" H 1850 2224 50  0000 C CNN
F 2 "Connector_JST:JST_PH_B8B-PH-SM4-TB_1x08-1MP_P2.00mm_Vertical" H 2000 2300 50  0001 C CNN
F 3 "" H 2000 2300 50  0001 C CNN
	1    1850 1850
	1    0    0    -1  
$EndComp
$Comp
L RFID_Multiplexeur-cache:RF_RFID_RC522 U3
U 1 1 5F0BA736
P 1850 2550
F 0 "U3" H 1850 3015 50  0000 C CNN
F 1 "RF_RFID_RC522" H 1850 2924 50  0000 C CNN
F 2 "Connector_JST:JST_PH_B8B-PH-SM4-TB_1x08-1MP_P2.00mm_Vertical" H 2000 3000 50  0001 C CNN
F 3 "" H 2000 3000 50  0001 C CNN
	1    1850 2550
	1    0    0    -1  
$EndComp
$Comp
L RFID_Multiplexeur-cache:RF_RFID_RC522 U4
U 1 1 5F0D6A84
P 1850 3250
F 0 "U4" H 1850 3715 50  0000 C CNN
F 1 "RF_RFID_RC522" H 1850 3624 50  0000 C CNN
F 2 "Connector_JST:JST_PH_B8B-PH-SM4-TB_1x08-1MP_P2.00mm_Vertical" H 2000 3700 50  0001 C CNN
F 3 "" H 2000 3700 50  0001 C CNN
	1    1850 3250
	1    0    0    -1  
$EndComp
$Comp
L RFID_Multiplexeur-cache:RF_RFID_RC522 U5
U 1 1 5F0F2D69
P 1850 3950
F 0 "U5" H 1850 4415 50  0000 C CNN
F 1 "RF_RFID_RC522" H 1850 4324 50  0000 C CNN
F 2 "Connector_JST:JST_PH_B8B-PH-SM4-TB_1x08-1MP_P2.00mm_Vertical" H 2000 4400 50  0001 C CNN
F 3 "" H 2000 4400 50  0001 C CNN
	1    1850 3950
	1    0    0    -1  
$EndComp
$Comp
L RFID_Multiplexeur-cache:RF_RFID_RC522 U6
U 1 1 5F10EECA
P 1850 4650
F 0 "U6" H 1850 5115 50  0000 C CNN
F 1 "RF_RFID_RC522" H 1850 5024 50  0000 C CNN
F 2 "Connector_JST:JST_PH_B8B-PH-SM4-TB_1x08-1MP_P2.00mm_Vertical" H 2000 5100 50  0001 C CNN
F 3 "" H 2000 5100 50  0001 C CNN
	1    1850 4650
	1    0    0    -1  
$EndComp
$Comp
L RFID_Multiplexeur-cache:RF_RFID_RC522 U7
U 1 1 5F12AFEB
P 1850 5350
F 0 "U7" H 1850 5815 50  0000 C CNN
F 1 "RF_RFID_RC522" H 1850 5724 50  0000 C CNN
F 2 "Connector_JST:JST_PH_B8B-PH-SM4-TB_1x08-1MP_P2.00mm_Vertical" H 2000 5800 50  0001 C CNN
F 3 "" H 2000 5800 50  0001 C CNN
	1    1850 5350
	1    0    0    -1  
$EndComp
$Comp
L RFID_Multiplexeur-cache:RF_RFID_RC522 U8
U 1 1 5F16357A
P 1850 6050
F 0 "U8" H 1850 6515 50  0000 C CNN
F 1 "RF_RFID_RC522" H 1850 6424 50  0000 C CNN
F 2 "Connector_JST:JST_PH_B8B-PH-SM4-TB_1x08-1MP_P2.00mm_Vertical" H 2000 6500 50  0001 C CNN
F 3 "" H 2000 6500 50  0001 C CNN
	1    1850 6050
	1    0    0    -1  
$EndComp
$Comp
L RFID_Multiplexeur-cache:RF_RFID_RC522 U16
U 1 1 5F17F9D0
P 4850 1100
F 0 "U16" H 4850 1565 50  0000 C CNN
F 1 "RF_RFID_RC522" H 4850 1474 50  0000 C CNN
F 2 "Connector_JST:JST_PH_B8B-PH-SM4-TB_1x08-1MP_P2.00mm_Vertical" H 5000 1550 50  0001 C CNN
F 3 "" H 5000 1550 50  0001 C CNN
	1    4850 1100
	1    0    0    -1  
$EndComp
$Comp
L RFID_Multiplexeur-cache:RF_RFID_RC522 U15
U 1 1 5F19BB3F
P 4850 1800
F 0 "U15" H 4850 2265 50  0000 C CNN
F 1 "RF_RFID_RC522" H 4850 2174 50  0000 C CNN
F 2 "Connector_JST:JST_PH_B8B-PH-SM4-TB_1x08-1MP_P2.00mm_Vertical" H 5000 2250 50  0001 C CNN
F 3 "" H 5000 2250 50  0001 C CNN
	1    4850 1800
	1    0    0    -1  
$EndComp
$Comp
L RFID_Multiplexeur-cache:RF_RFID_RC522 U14
U 1 1 5F1B7DA7
P 4850 2500
F 0 "U14" H 4850 2965 50  0000 C CNN
F 1 "RF_RFID_RC522" H 4850 2874 50  0000 C CNN
F 2 "Connector_JST:JST_PH_B8B-PH-SM4-TB_1x08-1MP_P2.00mm_Vertical" H 5000 2950 50  0001 C CNN
F 3 "" H 5000 2950 50  0001 C CNN
	1    4850 2500
	1    0    0    -1  
$EndComp
$Comp
L RFID_Multiplexeur-cache:RF_RFID_RC522 U13
U 1 1 5F1D3E7C
P 4850 3200
F 0 "U13" H 4850 3665 50  0000 C CNN
F 1 "RF_RFID_RC522" H 4850 3574 50  0000 C CNN
F 2 "Connector_JST:JST_PH_B8B-PH-SM4-TB_1x08-1MP_P2.00mm_Vertical" H 5000 3650 50  0001 C CNN
F 3 "" H 5000 3650 50  0001 C CNN
	1    4850 3200
	1    0    0    -1  
$EndComp
$Comp
L RFID_Multiplexeur-cache:RF_RFID_RC522 U12
U 1 1 5F1EFF35
P 4850 3900
F 0 "U12" H 4850 4365 50  0000 C CNN
F 1 "RF_RFID_RC522" H 4850 4274 50  0000 C CNN
F 2 "Connector_JST:JST_PH_B8B-PH-SM4-TB_1x08-1MP_P2.00mm_Vertical" H 5000 4350 50  0001 C CNN
F 3 "" H 5000 4350 50  0001 C CNN
	1    4850 3900
	1    0    0    -1  
$EndComp
$Comp
L RFID_Multiplexeur-cache:RF_RFID_RC522 U11
U 1 1 5F20C014
P 4850 4600
F 0 "U11" H 4850 5065 50  0000 C CNN
F 1 "RF_RFID_RC522" H 4850 4974 50  0000 C CNN
F 2 "Connector_JST:JST_PH_B8B-PH-SM4-TB_1x08-1MP_P2.00mm_Vertical" H 5000 5050 50  0001 C CNN
F 3 "" H 5000 5050 50  0001 C CNN
	1    4850 4600
	1    0    0    -1  
$EndComp
$Comp
L RFID_Multiplexeur-cache:RF_RFID_RC522 U10
U 1 1 5F2283C1
P 4850 5300
F 0 "U10" H 4850 5765 50  0000 C CNN
F 1 "RF_RFID_RC522" H 4850 5674 50  0000 C CNN
F 2 "Connector_JST:JST_PH_B8B-PH-SM4-TB_1x08-1MP_P2.00mm_Vertical" H 5000 5750 50  0001 C CNN
F 3 "" H 5000 5750 50  0001 C CNN
	1    4850 5300
	1    0    0    -1  
$EndComp
$Comp
L RFID_Multiplexeur-cache:RF_RFID_RC522 U9
U 1 1 5F244940
P 4850 6000
F 0 "U9" H 4850 6465 50  0000 C CNN
F 1 "RF_RFID_RC522" H 4850 6374 50  0000 C CNN
F 2 "Connector_JST:JST_PH_B8B-PH-SM4-TB_1x08-1MP_P2.00mm_Vertical" H 5000 6450 50  0001 C CNN
F 3 "" H 5000 6450 50  0001 C CNN
	1    4850 6000
	1    0    0    -1  
$EndComp
$Comp
L RFID_Multiplexeur-cache:Regulator_Linear_NCV4274ADT33RKG U18
U 1 1 5F27FF84
P 9850 950
F 0 "U18" H 9850 1242 50  0000 C CNN
F 1 "Regulator_Linear_NCV4274ADT33RKG" H 9850 1151 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:TO-252-3_TabPin4" H 9800 1500 50  0001 C CNN
F 3 "" H 10350 1300 50  0001 C CNN
	1    9850 950 
	1    0    0    -1  
$EndComp
Wire Wire Line
	7850 2150 7850 2250
Wire Wire Line
	7550 2150 7850 2150
$Comp
L power:+5V #PWR0103
U 1 1 5E060B16
P 7850 2250
F 0 "#PWR0103" H 7850 2100 50  0001 C CNN
F 1 "+5V" H 7865 2423 50  0000 C CNN
F 2 "" H 7850 2250 50  0001 C CNN
F 3 "" H 7850 2250 50  0001 C CNN
	1    7850 2250
	1    0    0    1   
$EndComp
$Comp
L RFID_Multiplexeur-cache:Device_R R20
U 1 1 5F314249
P 8300 2300
F 0 "R20" H 8370 2346 50  0000 L CNN
F 1 "Device_R" H 8370 2255 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 8230 2300 50  0001 C CNN
F 3 "" H 8300 2300 50  0001 C CNN
	1    8300 2300
	1    0    0    -1  
$EndComp
$Comp
L RFID_Multiplexeur-cache:Device_R R30
U 1 1 5F315287
P 8300 2700
F 0 "R30" H 8370 2746 50  0000 L CNN
F 1 "Device_R" H 8370 2655 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 8230 2700 50  0001 C CNN
F 3 "" H 8300 2700 50  0001 C CNN
	1    8300 2700
	1    0    0    -1  
$EndComp
$Comp
L RFID_Multiplexeur-cache:power_GND #PWR0122
U 1 1 5F3178A8
P 8300 2950
F 0 "#PWR0122" H 8300 2700 50  0001 C CNN
F 1 "power_GND" H 8305 2777 50  0000 C CNN
F 2 "" H 8300 2950 50  0001 C CNN
F 3 "" H 8300 2950 50  0001 C CNN
	1    8300 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	8300 2450 8300 2500
Wire Wire Line
	7850 2150 8300 2150
Connection ~ 7850 2150
Wire Wire Line
	8300 2850 8300 2950
Text GLabel 8500 2500 2    50   Input ~ 0
BatLevel
Wire Wire Line
	8300 2500 8500 2500
Connection ~ 8300 2500
Wire Wire Line
	8300 2500 8300 2550
Text GLabel 10350 4550 2    50   Input ~ 0
BatLevel
Wire Wire Line
	10250 4550 10350 4550
$EndSCHEMATC
