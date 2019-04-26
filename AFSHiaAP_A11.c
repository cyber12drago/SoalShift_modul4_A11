#define FUSE_USE_VERSION 28
#include <fuse.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>
#include <sys/time.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>


static const char *dirpath = "/home/cyber12drago/shift4";

static int a11_getattr(const char *path, struct stat *stbuf)
{
  int res,i,j;
  char characterlist[1000]="qE1~ YMUR2\"`hNIdPzi%^t@(Ao:=CQ,nx4S[7mHFye#aT6+v)DfKL$r?bkOGB>}!9_wV']jcp5JZ&Xl|\\8s;g<{3.u*W-0";
  char fpath[1000],cekname[1000];
    
  strcpy(cekname,path);  
  if(strcmp(cekname,".")!=0 && strcmp(cekname,"..")!=0){  
      for(i=0;i<strlen(cekname);i++){
            for(j=0;j<strlen(characterlist);j++){
                  if(cekname[i]==characterlist[j]){
                        j=j+17;
                        if(j>=strlen(characterlist)){
							j=j-strlen(characterlist);
						}
                        cekname[i]=characterlist[j];
                        break;
                  }
            }
        }
   }
	sprintf(fpath,"%s%s",dirpath,cekname);

	res = lstat(fpath, stbuf);

	if (res == -1)
		return -errno;

	return 0;
}

static int a11_readdir(const char *path, void *buf, fuse_fill_dir_t filler,
		       off_t offset, struct fuse_file_info *fi)
{
	int i,j,tahun;  
    char fpath[1000],cekname[1000];
    char soalno3[1000],fileno3[1000],waktuno3[2064];
    char characterlist[1000]="qE1~ YMUR2\"`hNIdPzi%^t@(Ao:=CQ,nx4S[7mHFye#aT6+v)DfKL$r?bkOGB>}!9_wV']jcp5JZ&Xl|\\8s;g<{3.u*W-0";
	if(strcmp(path,"/") == 0)
	{
		path=dirpath;
		sprintf(fpath,"%s",path);
	}
	else {
        strcpy(cekname,path);
        for(i=0;i<strlen(cekname);i++){
            for(j=0;j<strlen(characterlist);j++){
                  if(cekname[i]==characterlist[j]){
                        j=j+17;
                        if(j>=strlen(characterlist)){
							j=j-strlen(characterlist);
						}
                        cekname[i]=characterlist[j];
                        break;
                  }
            }
        }
        sprintf(fpath, "%s%s",dirpath,cekname);
    }
	int res = 0;

	DIR *dp;
	struct dirent *de;
	(void) offset;
	(void) fi;

	dp = opendir(fpath);
	if (dp == NULL)
		return -errno;

	while ((de = readdir(dp)) != NULL) {
		struct stat sta;
		memset(&sta, 0, sizeof(sta));
        sprintf(soalno3,"%s/%s",fpath,cekname);
		strcpy(cekname,de->d_name);
        stat(soalno3,&sta);
        sta.st_ino = de->d_ino;
        sta.st_mode = de->d_type << 12;
        if(strcmp(cekname,".")!=0 && strcmp(cekname,"..")!=0){
                if((((strcmp(getpwuid(sta.st_uid)->pw_name,"chipset"))==0)||((strcmp(getpwuid(sta.st_uid)->pw_name,"ic_controller"))==0))&&((strcmp(getgrgid(sta.st_gid)->gr_name,"rusak"))==0)){
                    FILE * simpan;
                    struct tm *times=localtime(&sta.st_atime);
                    tahun = times->tm_year + 1900;
                    sprintf(fileno3, "%s/V[EOr[c[Y`HDH", dirpath);
                    sprintf(waktuno3, "%s %d %d | time and date : %02d:%02d:%02d [%02d %02d %04d]\n",soalno3, sta.st_uid, sta.st_gid, times->tm_hour, times->tm_min, times->tm_sec, times->tm_mday, times->tm_mon, tahun);
                    simpan = fopen(fileno3, "a+");
                    fputs(waktuno3,simpan);
                    fclose(simpan);
                    remove(soalno3);
                    
                }    
                else{
                    for(i=0;i<strlen(cekname);i++){
                        for(j=0;j<strlen(characterlist);j++){
                            if(cekname[i]==characterlist[j]){
                                if(j-17<0){
                                    j=j-17+strlen(characterlist);
                                    cekname[i]=characterlist[j];
                                }
                                else{
                                    cekname[i]=characterlist[(j-17)];
                                }
                                break;
                            }
                        }
                    }
                }
        }
		res = (filler(buf, cekname, &sta, 0));
			if(res!=0) break;
	}
	closedir(dp);
	return 0;
}

static int a11_read(const char *path, char *buf, size_t size, off_t offset,
		    struct fuse_file_info *fi)
{ 
    char fpath[1000];
	if(strcmp(path,"/") == 0)
	{
		path=dirpath;
		sprintf(fpath,"%s",path);
	}
	else {
        sprintf(fpath, "%s%s",dirpath,path);

    }
	int res = 0;
	int fd = 0;
	(void) fi;
	fd = open(fpath, O_RDONLY);
	if (fd == -1)
		return -errno;

	res = pread(fd, buf, size, offset);
	if (res == -1)
		res = -errno;

	close(fd);
	return res;
}

static struct fuse_operations a11_oper = {
	 .getattr    	= a11_getattr,
	 .readdir    	= a11_readdir,
	 .read		    = a11_read,
};

int main(int argc, char *argv[])
{
	umask(0);
	return fuse_main(argc, argv, &a11_oper, NULL);
}

