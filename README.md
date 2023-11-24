<a name="atas"></a>

## Helpful Links
[PEDOMAN](https://docs.google.com/document/d/1vnoqQK18ECL8PEAkYbjM-9g1MRGTI7hOLv6GKHlGnuc/edit)

[SPESIFIKASI](https://docs.google.com/document/d/1yy0SLsXEE0e-ZBxMSrd0Gz9AOSWqJw1trtTqDjeyfsk/edit)

[Laporan](https://docs.google.com/document/d/1vvcpjb0gBg7fAZ2sz8jaaZ33nvVweUy7/edit)

## Tentang Aplikasi

<div align="center">
    <h2>Bur Bir</h2>
    <p>By Kelompok J</p>
    <img src="readme/burbir.png" alt="burbir" style="max-width:20em;"></img>
    <br/>
    <br/>
</div>


Klenting Kuning sedang sedih karena dia dirundung oleh ibu tirinya di aplikasi sosial media yang sedang beken saat zaman itu, yaitu Y. Dia dirundung karena dia berhasil memikat hati Ande-Ande Lumut. Ibu tirinya kesal, karena menurutnya, yang pantas untuk menjadi pasangan dari Ande-Ande Lumut adalah saudara tiri dari Klenting Kuning, yaitu Klenting Biru dan Klenting Merah. Klenting Kuning dikumpulkan di Y Spaces, tempat live audio, yang kelak disebut sebagai Kuning Space untuk dirundung oleh ibu tirinya bersama dengan anak-anaknya.

“Kuning, saya ini perwakilan Klenting Biru dan Klenting Merah. Saya sudah panggil advokat saya untuk bawa kasus ini ke meja hijau. Jadi kamu jangan macam-macam ya!”.
 
Klenting Kuning yang mendengar ancaman dari Ibu tirinya pun ketakutan dengan ancaman tersebut. Apalagi, ibu tirinya ini merupakan seorang aktivis HAM yang ayahnya merupakan salah satu pejabat terkenal di zamannya, dan begitu pula adiknya. Kakak dari suaminya juga merupakan salah satu kepala pejabat yang terkenal. Yang paling menyeramkan, dosen dari ibu tirinya merupakan salah satu petinggi partai di zaman itu.

Ande-Ande Lumut yang iba mendengar kisah Klenting Kuning kemudian berencana untuk membuat pengganti sosial media yang beken di zaman itu dimana ibu tiri dan saudara jahatnya dicekal dari pendaftaran, yang kelak dinamai BurBir (Burung Biru). Akan tetapi, dia tidak pandai dalam menggunakan bahasa C, sehingga kami, anak buah dari Yuyu Kangkang, diminta untuk membantu Ande-Ande Lumut membuat Aplikasi BurBir di CLI.


<p align="right">(<a href="#atas">kembali</a>)</p>

## Cara Kompilasi Program
Pertama-tama Clone repository terlebih dahulu
```
git clone https://github.com/Benardo07/Tubes-Alstrukdat-Kelompok-J.git
```

Jika ingin mengkompilasi main program dan semua drivers secara bersamaan
Tuliskan command berikut di **folder utama** project ini, yaitu folder yang sama tempat **Makefile** berada.

```shell
$ make
```

**Note**: Gunakan Git Bash / WSL jika Anda menggukanan Sistem Operasi Windows


### Test Driver Program

Jika hanya ingin mengkompilasi drivers dari setiap ADT
```shell
$ make drivers
```
<p align="right">(<a href="#atas">kembali</a>)</p>

## Cara Menjalankan Program
Setelah dikompilasi, jalankan program dengan memanggil langsung *executables* melalui terminal dengan menulis

```shell
$ ./main
```

sebelum memanggil program, pastikan  *Current Working Directory* terminal berada di **folder utama** program.

 *Current Working Directory* terminal dapat dilihat dengan menulis

 ```shell
 $ cwd
 ```
 atau
 ```shell
 $ pwd
 ```


### Test Driver Program
Test program dapat dijalankan dengan memanggil masing-masing *binary file* yang sesuai dengan nama ADT, contoh

```shell
$ ./(nama_driveradt)
```

### List nama_driveradt :
- driver_time : untuk Unit Test ADT Sederhana (Time)
- driver_datetime : untuk Unit Test ADT Sederhana (Datetime)
- driver_listpengguna : untuk Unit Test ADT List dengan Struktur Data Array Statik
- driver_foto : untuk Unit Test ADT Matriks
- driver_listdin : untuk Unit Test ADT List dengan Struktur Data Array Dinamik
- driver_charmachine : untuk Unit Test Mesin Karakter
- driver_wordmachine : untuk Unit Test Mesin Kalimat
- driver_prioqueue : untuk Unit Test ADT Priority Queue
- driver_drafstack : untuk Unit Test ADT Stack
- driver_listlinier : untuk Unit Test ADT List dengan Struktur Data Berkait
- driver_tree : untuk Unit Test ADT Tree
- driver_graf : untuk Unit Test ADT Graf dengan Representasi Adjacency Matrix
<p align="right">(<a href="#atas">kembali</a>)</p>

## Anggota Kelompok
| NIM |Nama |
|-----|-----|
|13522002|Ariel Herfrison|
|13522007|Irfan Sidiq Permana|
|13522021|Filbert|
|13522025|Debrina Veisha Rashika W|
|13522055|Benardo|

<p align="right">(<a href="#atas">kembali</a>)</p>

## Daftar Fitur
| No. | Nama Fitur | Status |
|-----|------------|:------:|
|1 |DAFTAR|:heavy_check_mark:|
|2 |MASUK|:heavy_check_mark:|
|3 |GANTI_PROFIL|:heavy_check_mark:|
|4 |LIHAT_PROFIL|:heavy_check_mark:|
|5 |ATUR_JENIS_AKUN|:heavy_check_mark:|
|6 |UBAH_FOTO_PROFIL|:heavy_check_mark:|
|7 |DAFTAR_TEMAN|:heavy_check_mark:|
|8 |HAPUS_TEMAN|:heavy_check_mark:|
|9 |TAMBAH_TEMAN|:heavy_check_mark:|
|10|DAFTAR_PERMINTAAN_PERTEMANAN|:heavy_check_mark:|
|11|SETUJUI_PERTEMANAN|:heavy_check_mark:|
|12|KICAU|:heavy_check_mark:|
|13|KICAUAN|:heavy_check_mark:|
|14|SUKA_KICAUAN|:heavy_check_mark:|
|15|UBAH_KICAUAN|:heavy_check_mark:|
|16|BALAS|:heavy_check_mark:|
|17|BALASAN|:heavy_check_mark:|
|18|HAPUS_BALASAN|:heavy_check_mark:|
|19|BUAT_DRAF|:heavy_check_mark:|
|20|LIHAT_DRAF|:heavy_check_mark:|
|21|UTAS|:heavy_check_mark:|
|22|SAMBUNG_UTAS|:heavy_check_mark:|
|23|HAPUS_UTAS|:heavy_check_mark:|
|24|CETAK_UTAS|:heavy_check_mark:|
|25|SIMPAN|:heavy_check_mark:|
|26|MUAT|:heavy_check_mark:|
|27|KELUAR|:heavy_check_mark:|
|28|TUTUP_PROGRAM|:heavy_check_mark:|

<p align="right">(<a href="#atas">kembali</a>)</p>
