# Der gegebene Binär-String
binary_input = "01111111"

# Den Dateipfad zur EXE-Datei angeben
dateipfad = "deine_datei.exe"

# Die Datei im binären Schreibmodus öffnen und den Binär-String schreiben
with open(dateipfad, 'wb') as datei:
    # Binär-String in Bytes umwandeln
    binary_data = bytes(int(binary_input, 2).to_bytes((len(binary_input) + 7) // 8, 'big'))

    # Binärdaten in die Datei schreiben
    datei.write(binary_data)

# Erfolgsmeldung
print(f"Die Daten wurden in die Datei {dateipfad} geschrieben.")
