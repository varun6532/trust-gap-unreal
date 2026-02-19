#include "NetworkHelper.h"
#include "Sockets.h"
#include "SocketSubsystem.h"
#include "IPAddress.h"

void UNetworkHelper::SendUDPMessage(const FString& Message)
{
    ISocketSubsystem* SocketSubsystem = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM);

    TSharedRef<FInternetAddr> Addr = SocketSubsystem->CreateInternetAddr();
    bool bIsValid;

    Addr->SetIp(TEXT("127.0.0.1"), bIsValid);
    Addr->SetPort(9000);

    FSocket* Socket = SocketSubsystem->CreateSocket(NAME_DGram, TEXT("UDP_SOCKET"), false);

    if (Socket)
    {
        FTCHARToUTF8 Converter(*Message);
        int32 BytesSent = 0;

        Socket->SendTo(
            (uint8*)Converter.Get(),
            Converter.Length(),
            BytesSent,
            *Addr
        );

        Socket->Close();
        SocketSubsystem->DestroySocket(Socket);
    }
}
