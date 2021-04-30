<?xml version="1.0" encoding="UTF-8" ?>
<Package name="NaoChallege2021-214" format_version="4">
    <Manifest src="manifest.xml" />
    <BehaviorDescriptions>
        <BehaviorDescription name="behavior" src="main" xar="behavior.xar" />
        <BehaviorDescription name="behavior" src="saluto" xar="behavior.xar" />
        <BehaviorDescription name="behavior" src="domanda1" xar="behavior.xar" />
    </BehaviorDescriptions>
    <Dialogs>
        <Dialog name="dialogo1" src="domanda1/dialogo1/dialogo1.dlg" />
    </Dialogs>
    <Resources />
    <Topics>
        <Topic name="dialogo1_enu" src="domanda1/dialogo1/dialogo1_enu.top" topicName="dialogo1" language="en_US" />
        <Topic name="dialogo1_iti" src="domanda1/dialogo1/dialogo1_iti.top" topicName="dialogo1" language="it_IT" />
    </Topics>
    <IgnoredPaths />
</Package>
