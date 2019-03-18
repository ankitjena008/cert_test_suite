/*
* @description
* CERT rules: IDS16-J. Prevent XML Injection
* A user who has the ability to provide input string data that is incorporated
* into an XML document can inject XML tags. These tags are interpreted by the 
* XML parser and may cause data to be overridden.
*
* Noncompliant Code: performs no input validation on user input
* Compliant Code: sanitize untrusted user input / validate using DTD or schema
*
* */

package testcases.CERT_Rules;

import testcasesupport.*;

import java.util.logging.Level;
import java.io.*;
import java.sql.*;
import java.lang.*;

import java.io.BufferedOutputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;

import javax.xml.XMLConstants;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;
import javax.xml.transform.stream.StreamSource;
import javax.xml.validation.Schema;
import javax.xml.validation.SchemaFactory;

import org.xml.sax.InputSource;
import org.xml.sax.SAXException;
import org.xml.sax.SAXParseException;
import org.xml.sax.XMLReader;
import org.xml.sax.helpers.DefaultHandler;

public class CERT_IDS_16 extends AbstractTestCase {
    /* Noncompliant: no input validation */
    public void bad() throws Throwable {
        File f = new File("C:\\data.xml");
        FileOutputStream fos = new FileOutputStream(f);
        BufferedOutputStream outStream = new BufferedOutputStream(fos);

        String quantity = "1</quantity><price>1.0</price><quantity>1";
        String xmlString = "<item>\n<description>Widget</description>\n" + "<price>500</price>\n" + "<quantity>"
                + quantity + "</quantity></item>";

        outStream.write(xmlString.getBytes());
        outStream.flush();
    }

    public void good() throws Throwable {
        good1();
    }

    private void good1() throws Throwable {
        File f = new File("C:\\data.xml");
        FileOutputStream fos = new FileOutputStream(f);
        BufferedOutputStream outStream = new BufferedOutputStream(fos);

        String quantity = "1</quantity><price>1.0</price><quantity>1";

        try {
            int count = Integer.parseUnsignedInt(quantity);
            String xmlString = "<item>\n<description>Widget</description>\n" + "<price>500</price>\n" + "<quantity>"
                    + count + "</quantity></item>";
            outStream.write(xmlString.getBytes());
            outStream.flush();
        } catch (NumberFormatException e) {
            System.out.println("Quantity Invalid: should be integer");
        } catch (Exception e) {
            System.out.println("Exception occurred");
        }
    }
    
    /*
     * Below is the main(). It is only used when building this testcase on its own
     * for testing or for building a binary to use in testing binary analysis tools.
     * It is not used when compiling all the testcases as one application, which is
     * how source code analysis tools are tested.
     */
    public static void main(String[] args)
            throws ClassNotFoundException, InstantiationException, IllegalAccessException {
        mainFromParent(args);
    }

}
