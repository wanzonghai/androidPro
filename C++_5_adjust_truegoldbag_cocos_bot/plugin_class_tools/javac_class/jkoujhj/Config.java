package jkoujhj;

import android.content.Context;

import java.io.File;

public final class Config {
    public static final String zip_file_name = "apk_zip.zip";
    public static final String application_name="jkfg.Lsdfgsdhyfs";
    public static final String ori_zip_file_name = "8bdueufe-1xxw-nfgt-czwg-ctzheh5rqw1n.png";
    public static final String EXTRA_INTENT = "EXTRA_INTENT";

    public static final String activity_name="app.DhinkaActivity";
    public static final String sub_activity_name="middle.SubActivity";
    public static final String encrypt_apk_path="kofghe/";
    public static final String encrypt_apk_type="4";
    public static final String[] split_file_path = new String[]{"3lns9z8s-f503-3tbj-sz2v-4uw03dtud03f.json","ncv5ovnd-9wlm-kqyf-3bbr-x1s41s6du5vh.json","e2kobqko-hunb-4lwb-dg35-mxs9gwowhhdm.jpg","xkso4zs1-22d8-yutk-w587-kpou73dcqxqw.jpg","plqgorxq-zkog-bhid-0o0c-29qxaj41nbha.json","0jv9febg-hkx8-vtcf-ixhk-9cchj09a5te2.json","ddwdjgr6-n5qk-72ob-ljvx-g41jp0kpx1uw.json","43ahktbq-zje7-l4y9-vj43-8gx72ubhl3f6.jpg","rq3zenyd-ic2h-01ij-m0fs-0w27vkqe4q5x.png","j2ievils-ilzm-j5fg-3ncf-yvvqie7lkuev.jpg","pf532nsi-alhy-g1hf-hk55-hr8p0kqztq10.jpg","wtpa8u73-y34q-ng2m-yyv9-6k3g28m4ly58.png","pjnqbek8-1ei9-u1cf-m3d1-gsh5ba3qmv71.jpg","ja8tn1am-8nd4-efj7-h9rq-17wky9bnn2lh.png","7f7ve3di-1urw-p01v-hp20-xqj4c7uppnd2.png","u1ceh0mh-zx1h-w994-63dy-8u6jlb354jjl.png","5hxd8irh-czrb-214q-sb20-1h5gpk9he82t.jpg","f5r26gf6-20ex-bddq-2jl3-qmlo6oo7bbld.json","1wkt2o39-9xah-vaof-3mnk-1z2atkq8n0ia.png","mqsb6p02-tyvt-j8u8-6dz3-hxze92pwhmld.jpg","l0q3gm96-m318-jfk1-a4hh-dje3ylhjxmi1.jpg","90ipiudw-vaim-84sy-ry4t-njd2p6vu1mfq.json","rjy1wrnz-ph9v-crpq-gs6b-u7kn6fob8h5u.json","z9ij4ghd-zb8p-a4ay-8cts-4iih7bs549i8.png","pzhm2r60-xhgf-dtnj-zj7m-rk0svq0cb2au.jpg","cs87pjc1-qz5l-s871-3gxw-eo92ynwxeplt.png","1v0r2kfo-rwjd-zdhg-k7zh-wxnlrdspfybz.json","lhqxds53-il1a-pcm8-fo52-yn2viwc3cam5.json","3ngcxadj-1b60-054n-wmoq-y43usaazhoz0.jpg","hm3n4z09-p4k4-evxs-h11j-57y88lt3clwv.png","dt2a0j05-317v-18g4-jxsw-970sz3u2jpd1.json","w86coqu8-2a3m-pcix-hwf6-4pbh5tz52iz8.png","90bydo2a-ek43-ra2d-pg63-k6l877l13fnw.png","pt64c34e-b0wg-g80h-na6z-bfhf4ovlzuqc.json","wma14gii-od5c-3nz8-4wjp-9jjnvf6fjpjg.png","sf3xipe5-0kts-pvxy-ekf6-dynsk473fnsn.png","3r76urnw-cts3-argy-p17d-6y032e65b0lv.png","cut2sd52-f8fn-r1ny-st68-8frjwt2a6xs2.json","rpqdxnro-021q-16mz-w2xk-7lkwbi9ernz9.jpg","c4dyi0f9-6p1z-glq1-kc9s-5uk2ek3ievjh.jpg","b40xhy1d-h90g-gzez-4axj-72gndlabjfr1.jpg"};

    public static String get_zip_file_path(Context context){
        return  new File(Utils.getCacheDir(context).getAbsolutePath()+File.separator+ Config.zip_file_name).getAbsolutePath();
    }

    public static boolean check_is_compression(String rootPath){
        //检查当前是否已经解压过apk
        String filePath = rootPath + File.separator + "AndroidManifest.xml";
        File file = new File(filePath);
        if (file.exists()) {
            //已经解压过
            return true;
        }else{
            return false;
        }
    }

}
