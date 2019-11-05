import keyboard
import codecs

shift = False
shiftMap = {}
unShiftMap = {}


def remap_keyboard(src):
    def handler(event):
        global shift
        if (event.event_type == keyboard.KEY_DOWN):
            if(shift and (src in shiftMap)):
                keyboard.write(shiftMap[src])
                shift = True
            elif(src in unShiftMap):
                keyboard.write(unShiftMap[src])
            else:
                keyboard.write(src)
        else:
            keyboard.release(src)
    keyboard.hook_key(src, handler, suppress=True)


def shiftPressHandler(e):
    global shift
    shift = True


def shiftReleaseHandler(e):
    global shift
    shift = False


keyboard.on_press_key('shift', shiftPressHandler)
keyboard.on_release_key('shift', shiftReleaseHandler)

f = codecs.open("shift.csv", mode="r", encoding="utf-8")
for x in f:
    x = x.strip().split("\n")[0].split(",")
    remap_keyboard(x[0].lower())
    shiftMap[x[0].lower()] = x[1]

f = codecs.open("unshift.csv", mode="r", encoding="utf-8")
for x in f:
    x = x.strip().split("\n")[0].split(",")
    remap_keyboard(x[0].lower())
    unShiftMap[x[0].lower()] = x[1]

shiftMap[","] = '\u0998'
remap_keyboard(",")
keyboard.wait('esc')
