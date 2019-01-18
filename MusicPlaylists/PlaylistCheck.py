import sys
import csv

categories = []

rows = []
with open("playlists3.csv", newline='') as csvfile:
    playlist_reader = csv.reader(csvfile, delimiter='>', quotechar='|')

    for row in playlist_reader:
        rows.append(row)

volumes = {}
for row in rows:
    print(row[7])
    if(row[7] not in volumes):
        volumes[row[7]] = row[0:6]
    else:
        volumes[row[7]].append(row[0:6])

print(volumes)
