# Get WSL IP address
$remoteport = bash.exe -c "ip -4 addr show eth0 | grep -oP '(?<=inet\s)\d+(\.\d+){3}'"
$found = $remoteport -match '\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}';

if( $found ){
  $remoteport = $matches[0];
} else{
  echo "The Script Exited, the IP address of WSL2 cannot be found";
  exit;
}

# Define forward ports
$ports=@(1883,1880,8086);

# Listen address
$addr='0.0.0.0';
$ports_a = $ports -join ",";


# Remove firewall exception rules
iex "Remove-NetFireWallRule -DisplayName 'WSL2 Firewall Unlock' ";

# Add exception rules for inbound and outbound
iex "New-NetFireWallRule -DisplayName 'WSL2 Firewall Unlock' -Direction Outbound -LocalPort $ports_a -Action Allow -Protocol TCP";
iex "New-NetFireWallRule -DisplayName 'WSL2 Firewall Unlock' -Direction Inbound -LocalPort $ports_a -Action Allow -Protocol TCP";

# Ports forwards
for( $i = 0; $i -lt $ports.length; $i++ ){
  $port = $ports[$i];
  iex "netsh interface portproxy delete v4tov4 listenport=$port listenaddress=$addr";
  iex "netsh interface portproxy add v4tov4 listenport=$port listenaddress=$addr connectport=$port connectaddress=$remoteport";
}