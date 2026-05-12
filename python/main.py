from arduino.app_utils import App, Bridge
from audioplayer import AudioPlayer  
import time

player = AudioPlayer()

for attempt in range(30):
    status = player.status()

    if status.get("ok"):
        Bridge.call("audio",1)
        print("Audio backend ready")
        break

    print("Audio backend not ready yet...")
    time.sleep(2)


player.set_volume(50)

radios = {
    "info": "http://icecast.radiofrance.fr/franceinfo-lofi.mp3",
    "rtl": "https://icecast.rtl.fr/rtl-1-44-128",
    "inter": "http://direct.radiofrance.fr/live/franceinter-midfi.mp3",
    "musique": "http://icecast.radiofrance.fr/francemusique-midfi.mp3",
    "nostalgie": "https://streaming.nrjaudio.fm/oug7girb92oc?origine=fluxradios",
    "mradio": "http://mfmwr-007.ice.infomaniak.ch/mfmwr-007.mp3"
}

def api_radio(name):
    name = str(name).strip().lower()
    url = radios.get(name)
    if url:
        print(f"Joue {name}: {url}")
        player.stop()
        time.sleep(0.3)
        player.play(url)  # Brick gère guillemets interne        
    else:
        print(f"Doublon ou inconnu: {name}")

def api_volume(vol):
    vol = max(0, min(100, int(vol)))
    player.set_volume(vol)
    print(f"Volume {vol}")

def api_stop():
    player.stop()
    print("Stop")
    

Bridge.provide("api_radio", api_radio)
Bridge.provide("api_volume", api_volume)
Bridge.provide("api_stop", api_stop)


App.run()
