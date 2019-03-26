import java.lang.reflect.InvocationTargetException;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLClassLoader;
import java.net.URLStreamHandlerFactory;
import java.security.CodeSource;
import java.security.PermissionCollection;
import java.security.Permissions;

//SEC_07
class MyLoader extends URLClassLoader{
    public MyLoader(URL[] urls, ClassLoader parent, URLStreamHandlerFactory factory) {
        super(urls, parent, factory);
    }
    public MyLoader(URL[] urls) {
        super(urls);
    }
    public MyLoader(URL[] urls, ClassLoader parent) {
        super(urls, parent);
    }
    @Override
    protected PermissionCollection getPermissions(CodeSource cs) {
        PermissionCollection pc = new Permissions();
        // Allow exit from the VM anytime
        pc.add(new RuntimePermission("exitVM"));
        return pc;
    }
}
 