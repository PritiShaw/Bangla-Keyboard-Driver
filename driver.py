import keyboard
import codecs

shift = False
shiftMap = {}
unShiftMap = {}
def remap_keyboard(src, bangla):    
    def handler(event):
        if (event.event_type == keyboard.KEY_DOWN):
            if(shift and (src in shiftMap)):
                keyboard.write(shiftMap[src])
            elif(src in unShiftMap):
                keyboard.write(unShiftMap[src])
            else:
                keyboard.write(src)
        else:
            keyboard.release(src)
    keyboard.hook_key(src, handler, suppress=True)

def shiftHandler(e):
    global shift
    shift = not shift

keyboard.on_press_key('shift',shiftHandler)

f = codecs.open("shift.csv", mode="r", encoding="utf-8")
for x in f:
    x = x.strip().split("\n")[0].split(",")
    remap_keyboard(x[0].lower(),x[1])
    shiftMap[x[0]] = x[1]    

f = codecs.open("unshift.csv", mode="r", encoding="utf-8")
for x in f:
    x = x.strip().split("\n")[0].split(",")
    remap_keyboard(x[0],x[1])
    unShiftMap[x[0]] = x[1]
shiftMap[","]="ষ"
remap_keyboard(",","ষ")
keyboard.wait('esc')