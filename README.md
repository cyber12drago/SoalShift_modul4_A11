# SoalShift_modul4_A11
## Soal 1
Semua nama file dan folder harus terenkripsi
Enkripsi yang Atta inginkan sangat sederhana, yaitu Caesar cipher. Namun, Kusuma mengatakan enkripsi tersebut sangat mudah dipecahkan. Dia menyarankan untuk character list diekspansi,tidak hanya alfabet, dan diacak. Berikut character list yang dipakai:

qE1~ YMUR2"`hNIdPzi%^t@(Ao:=CQ,nx4S[7mHFye#aT6+v)DfKL$r?bkOGB>}!9_wV']jcp5JZ&Xl|\8s;g<{3.u*W-0

Misalkan ada file bernama “halo” di dalam folder “INI_FOLDER”, dan key yang dipakai adalah 17, maka:
“INI_FOLDER/halo” saat belum di-mount maka akan bernama “n,nsbZ]wio/QBE#”, saat telah di-mount maka akan otomatis terdekripsi kembali menjadi “INI_FOLDER/halo” .
Perhatian: Karakter ‘/’ adalah karakter ilegal dalam penamaan file atau folder dalam *NIX, maka dari itu dapat diabaikan

### Langkah-langkah
1. Dibuat file yang terenkripsi 'Caesar Cipher' dengan character list sesuai soal dan diacak.
2. Setelah dimount nama file berubah dan sudah terdekripsi.
## Soal 3
Sebelum diterapkannya file system ini, Atta pernah diserang oleh hacker LAPTOP_RUSAK yang menanamkan user bernama “chipset” dan “ic_controller” serta group “rusak” yang tidak bisa dihapus. Karena paranoid, Atta menerapkan aturan pada file system ini untuk menghapus “file bahaya” yang memiliki spesifikasi:
Owner Name     : ‘chipset’ atau ‘ic_controller’
Group Name    : ‘rusak’
Tidak dapat dibaca
Jika ditemukan file dengan spesifikasi tersebut ketika membuka direktori, Atta akan menyimpan nama file, group ID, owner ID, dan waktu terakhir diakses dalam file “filemiris.txt” (format waktu bebas, namun harus memiliki jam menit detik dan tanggal) lalu menghapus “file bahaya” tersebut untuk mencegah serangan lanjutan dari LAPTOP_RUSAK.

### Langkah-langkah
1. Cek apakah file memiliki owner 'chipset' atau 'ic_controller' dan memiliki group 'rusak'
```
if(strcmp(cekname,".")!=0 && strcmp(cekname,"..")!=0){
if((((strcmp(getpwuid(sta.st_uid)->pw_name,"chipset"))==0)||((strcmp(getpwuid(sta.st_uid)->pw_name,"ic_controller"))==0))&&((strcmp(getgrgid(sta.st_gid)->gr_name,"rusak"))==0)){
```
2. Tentukan apa saja yang akan disimpan di file .txt
```
sprintf(waktuno3, "%s %d %d | time and date : %02d:%02d:%02d [%02d %02d %04d]\n",soalno3, sta.st_uid, sta.st_gid, times->tm_hour, times->tm_min, times->tm_sec, times->tm_mday, times->tm_mon, tahun);
```
3. Simpan input ke dalam .txt
```
simpan = fopen(fileno3, "a+");
fputs(waktuno3,simpan);
```
4. Hilangkan "file bahaya"
```
remove(soalno3);
```
## Soal 4
Pada folder YOUTUBER, setiap membuat folder permission foldernya akan otomatis menjadi 750. Juga ketika membuat file permissionnya akan otomatis menjadi 640 dan ekstensi filenya akan bertambah “.iz1”. File berekstensi “.iz1” tidak bisa diubah permissionnya dan memunculkan error bertuliskan “File ekstensi iz1 tidak boleh diubah permissionnya.”
