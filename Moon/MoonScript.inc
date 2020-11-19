[Variables]
WINDOW-DIM=450
WINDOW-CENTER=(#WINDOW-DIM#/2)
OFFSET=-111

[AngleArgument]
Measure=Calc
Formula=Rad(Counter/100)

[MeasurePosX]
Measure=Calc
DynamicVariables=1
Formula=( 8 - 150*cos( 5.7*[AngleArgument] ) ) * 5 + #OFFSET# + #SCREENAREAWIDTH# / 2

[MeasureVUX]
Measure=Calc
DynamicVariables=1
Formula=( 8 - 150*cos( 5.7*[AngleArgument] ) ) * 5 + #OFFSET# * 1.20 + #SCREENAREAWIDTH# / 2

[MeasurePosY]
Measure=Calc
DynamicVariables=1
Formula=( 7 - 10*sin( 5.7*[AngleArgument] ) ) * 10 + #OFFSET# * 1.8 + #SCREENAREAHEIGHT# / 2
IfCondition=MeasurePosY < 400
IfTrueAction=[!ZPos -2][!ZPos -2 "VisBubbleMoonOrbit"]
IfFalseAction=[!ZPos -2 "Earth"][!ZPos -2 "VisBubbleEarth"]

[MeasureVUY]
Measure=Calc
DynamicVariables=1
Formula=( 7 - 10*sin( 5.7*[AngleArgument] ) ) * 10 + #OFFSET# * 2.01 + #SCREENAREAHEIGHT# / 2
//IfCondition=MeasurePosY < 400
//IfTrueAction=[!ZPos -2]
//IfFalseAction=[!ZPos -2 "Earth"][!ZPos -2 "VisBubbleEarth"]

//IfTrueAction[!SetOption EarthMeter ImageName "Kebab"]
//IfFalseAction[!SetOption EarthMeter ImageName "#CURRENTPATH#\Earth noglow.png"]
//OnUpdateAction=[!UpdateMeter EarthMeter]
//IfTrueAction[!HideMeter "EarthMeter"]
//IfFalseAction[!ShowMeter "EarthMeter"]

//IfTrueAction[!SetOption TextMeter Text "True"]
//IfFalseAction[!SetOption TextMeter Text "False"]
//OnUpdateAction=[!UpdateMeter TextMeter][!Redraw]
//[SetZPosition]

//[CounterThingy]
//Measure=Calc
//Formula=Counter

[MoonMeter]
Meter=Image
DynamicVariables=1
ImageName=#CURRENTPATH#\Moon Solo.png
OnUpdateAction=[!Move "[MeasureVUX]" "[MeasureVUY]" "VisBubbleMoonOrbit"]
//OnUpdateAction=[!SetVariable AngleStartDeg CounterThingy "VisBubbleMoonOrbit"]

//MaskImageName=#CURRENTPATH#\Earth Mask.png
//ImageTint=#HUD-COL-1#
//ImageAlpha=( 255 + 127*sin( 5.7*[AngleArgument] ) )


X=[MeasurePosX]
Y=[MeasurePosY]

//[EarthMeter]
//Meter=Image
//ImageName=#CURRENTPATH#\Earth noglow.png
//X=660
//Y=242

//if ()
//X=OFFSET*( 8 - 150*cos( 5.7*[AngleArgument] ) ) * 2
//Y=( 7 - 10*sin( 5.7*[AngleArgument] ) ) * 2
//W=10
AntiAlias=1

[MoveVUSkin]
Meter=Calc
Formula=1
OnUpdateAction=[!Move (#CURRENTCONFIGX# + 200) (#CURRENTCONFIGY# + 100) "VisBubbleMoonOrbit"]
DynamicVariables=1




//[TextMeter]
//Meter=String
//ImageTint=#HUD-COL-1#
//ImageAlpha=( 255 + 127*sin( 5.7*[AngleArgument] ) )
//FontSize=25
//FontColor=white
//AntiAlias=1
//DynamicVariables=1
//MeasureName=MeasurePos
//cunt=Counter/10
//Text=X:[MeasurePosX] #CRLF#Y:[MeasurePosY] #CRLF#Time:[AngleArgument] #CRLF#Below 400:
//X=#CURRENTCONFIGX#
//Y=#CURRENTCONFIGY# 
