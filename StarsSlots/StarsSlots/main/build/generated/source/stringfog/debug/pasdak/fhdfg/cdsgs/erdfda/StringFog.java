package pasdak.fhdfg.cdsgs.erdfda;


import com.github.megatronking.stringfog.xor.StringFogImpl;

/**
 * Generated code from StringFog gradle plugin. Do not modify!
 */
public final class StringFog {
  private static final StringFogImpl IMPL = new StringFogImpl();

  public static String encrypt(String value) {
    return IMPL.encrypt(value, "zpt8lb5il9autfzn");
  }

  public static String decrypt(String value) {
    return IMPL.decrypt(value, "zpt8lb5il9autfzn");
  }

  public static boolean overflow(String value) {
    return IMPL.overflow(value, "zpt8lb5il9autfzn");
  }

}
