$TestData = @(
                @{ "sbblksize" = "1024x1024"; "bitmapgen" = "gdi"; "bnds" = "Z0:5T0:2C0:2"; "tileinfo"= "4x4;10%" ; "expectedhash"="F02A3C33EBF72B814EFC8831B51D3389"},
                @{ "sbblksize" = "1600x1200"; "bitmapgen" = "gdi"; "bnds" = "Z0:1T0:1C0:2"; "expectedhash"="5839A112D778EA54B1935FFB6228C812" },
                @{ "sbblksize" = "1024x1024"; "bitmapgen" = "gdi"; "expectedhash"="AF65B495B134C18BA93C88E64104B6DC" }
             )


$Executable = "../../Build/VS/x64/Debug/CZIcmd.exe"
$TempCZIFilename=Join-Path -Path $env:TEMP -ChildPath "libCZIWriteTest"
#$TempCZIFilename="D:\libCZIWriteTest"

$loopCnt=0
ForEach ($i in $TestData) 
{ 
    $Args = @('--command','CreateCZI','-o',$TempCZIFilename)
    $Args += @('--guidofczi', '{22D355B7-A051-4F2E-8686-B50F2A3B154D}')
	$Args += @('--createczisbblkmetadata', '{\"StageXPosition\":-8906.346,\"StageYPosition\":-648.51}')
    
    if ($i["sbblksize"] -gt 0)
    {
        $Args += @('--createsubblocksize', $i["sbblksize"])
    }

    if ($i["bnds"] -gt 0)
    {
        $Args += @('--createbounds', $i["bnds"])
    }

    if ($i["tileinfo"] -gt 0)
    {
        $Args += @('--createtileinfo', $i["tileinfo"])
    }

    if ($i["bitmapgen"] -gt 0)
    {
        $Args += @('--bitmapgenerator', $i["bitmapgen"])
    }

    #Write-Host $Args
    & $Executable $Args *>$null

    $hashResult = Get-FileHash $TempCZIFilename'.czi' -Algorithm MD5

    if ($hashResult.Hash -ne $i["expectedhash"])
    {
        Write-Host "TEST#" (1+$loopCnt) " -> FAILED (is:" $hashResult.Hash " expected:" $i["expectedhash"] ")"
    }
    else
    {
        Write-Host "TEST#" (1+$loopCnt) " -> SUCCESS"
    }

    ($TempCZIFilename+'.czi') | Remove-Item
    $loopCnt=$loopCnt+1
}