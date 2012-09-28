property Namen : ""
tell application "Finder" to get item 1 of ((name of every disk whose local volume = false) as list)

