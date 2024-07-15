# WAV Files Processor

## Compile All Programs (All Modes)
```bash
make
```

## Compile One Program (Choose Mode)
```bash
make wavproc1
```
```bash
make wavproc2
```
```bash
make wavproc3
```
```bash
make wavproc4
```
```bash
make wavproc5
```
```bash
make wavproc6
```
```bash
make wavproc7
```

## Run Programs
Run each program using different sound files:

```bash
./wavproc1 < sounds/good.wav
```
```bash
./wavproc1 < sounds/1MB.wav
```
```bash
./wavproc1 < sounds/2MB.wav
```
```bash
./wavproc1 < sounds/5MB.wav
```
```bash
./wavproc1 < sounds/10MB.wav
```
```bash
./wavproc1 < sounds/bad_wave.wav
```
```bash
./wavproc1 < sounds/bad_sfc.wav
```
```bash
./wavproc1 < sounds/bad_wtf.wav
```
```bash
./wavproc1 < sounds/bad_ms.wav
```
```bash
./wavproc1 < sounds/bad_bys.wav
```
```bash
./wavproc1 < sounds/bad_bis.wav
```
```bash
./wavproc1 < sounds/bad_ba.wav
```
```bash
./wavproc1 < sounds/bad_data.wav
```
```bash
./wavproc1 < sounds/bad_insfd.wav
```
```bash
./wavproc1 < sounds/bad_sf.wav
```
```bash
./wavproc2 < sounds/LaughEvil.wav > LaughEvil2.wav
```
```bash
./wavproc2 < sounds/la.wav > la2.wav
```
```bash
./wavproc2 < sounds/8bitstereo.wav > 8bitstereo2.wav
```
```bash
./wavproc3 < sounds/LaughSarc.wav > LaughSarc3.wav
```
```bash
./wavproc3 < sounds/narc.wav > narc3.wav
```
```bash
./wavproc3 < sounds/8bitmono.wav > 8bitmono3.wav
```
```bash
./wavproc4 < sounds/8bitstereo.wav > 8bitstereo4.wav
```
```bash
./wavproc5 < sounds/8bitstereo.wav > 8bitstereo5.wav
```
```bash
./wavproc6 < sounds/8bitmono.wav > 8bitmono6.wav
```
```bash
./wavproc6 < sounds/8bitstereo.wav > 8bitstereo6.wav
```
```bash
./wavproc6 < sounds/la.wav > la6.wav
```
```bash
./wavproc7 > mysound.wav
```
```bash
./wavproc1 < sounds/mysound.wav
```

## After Execution
```bash
make clean
```