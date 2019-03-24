import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.sql.*;
import java.util.logging.Level;

public class Inject {
    // IDS_07 os command injection
    public void osCommandInject(String data) throws IOException, InterruptedException {
        String osCommand;
        if (System.getProperty("os.name").toLowerCase().indexOf("win") >= 0) {
            /* running on Windows */
            osCommand = "c:\\WINDOWS\\SYSTEM32\\cmd.exe /c dir ";
        } else {
            /* running on non-Windows */
            osCommand = "/bin/ls ";
        }
        Process process = Runtime.getRuntime().exec(osCommand + data);
        process.waitFor();
    }

    // IDS_00 sql injection
    // SQL_NONCONSTANT_STRING_PASSED_TO_EXECUTE
    public void sqlInject1(String data) throws ClassNotFoundException {
        Connection dbConnection = null;
        Statement sqlStatement = null;

        try {
            Class.forName("com.mysql.jdbc.Driver");
            // MSC_03: hard coded password
            dbConnection = DriverManager.getConnection("jdbc:mysql://localhost:3306/one", "root", "root");
            sqlStatement = dbConnection.createStatement();
            /*
             * POTENTIAL FLAW: data concatenated into SQL statement used in execute(), which
             * could result in SQL Injection
             */
            Boolean result = sqlStatement
                    .execute("insert into users (status) values ('updated') where name='" + data + "'");

            if (result) {
                System.out.println("Name, " + data + ", updated successfully");
            } else {
                System.out.println("Unable to update records for user: " + data);
            }
        } catch (SQLException exceptSql) {
            // handle exception here
        } finally {
            try {
                if (sqlStatement != null) {
                    sqlStatement.close();
                }
            } catch (SQLException exceptSql) {
                // handle exception here
            }
            try {
                if (dbConnection != null) {
                    dbConnection.close();
                }
            } catch (SQLException exceptSql) {
                // handle exception here
            }
        }
    }

    // SQL_PREPARED_STATEMENT_GENERATED_FROM_NONCONSTANT_STRING
    public void sqlInject2(String data) throws Throwable {
        Connection dbConnection = null;
        PreparedStatement sqlStatement = null;

        try {
            Class.forName("com.mysql.jdbc.Driver");
            // MSC_03: hard coded password
            dbConnection = DriverManager.getConnection("jdbc:mysql://localhost:3306/two", "root", "root");
            /*
             * POTENTIAL FLAW: data concatenated into SQL statement used in
             * prepareStatement() call, which could result in SQL Injection
             */
            sqlStatement = dbConnection
                    .prepareStatement("insert into users (status) values ('updated') where name='" + data + "'");

            Boolean result = sqlStatement.execute();

            if (result) {
                System.out.println("Name, " + data + ", updated successfully");
            } else {
                System.out.println("Unable to update records for user: " + data);
            }
        } catch (SQLException exceptSql) {
            // handle exception here
        } finally {
            try {
                if (sqlStatement != null) {
                    sqlStatement.close();
                }
            } catch (SQLException exceptSql) {
                // handle exception here
            }
            try {
                if (dbConnection != null) {
                    dbConnection.close();
                }
            } catch (SQLException exceptSql) {
                // handle exception here
            }
        }
    }

    public static void main (String[] args) throws Throwable {
        Inject obj = new Inject();
        try {
            obj.osCommandInject(args[0]);
        } catch (InterruptedException ie) {
            // handle exception
        } catch (IOException ioe) {
            // handle exception
        }
        
        obj.sqlInject1(args[1]);
        obj.sqlInject2(args[2]);
    }
}