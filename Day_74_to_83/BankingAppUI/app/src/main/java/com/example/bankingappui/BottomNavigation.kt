package com.example.bankingappui

import androidx.compose.foundation.background
import androidx.compose.foundation.layout.Row
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.AccountCircle
import androidx.compose.material.icons.filled.Home
import androidx.compose.material.icons.filled.Notifications
import androidx.compose.material.icons.filled.Wallet
import androidx.compose.material3.Icon
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.NavigationBar
import androidx.compose.material3.NavigationBarItem
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Modifier
import androidx.compose.ui.tooling.preview.Preview
import com.example.bankingappui.data.BottomNavigationItem


val Home = BottomNavigationItem(title = "Home",icon = Icons.Default.Home)
val Wallet = BottomNavigationItem(title = "Wallet",icon = Icons.Default.Wallet)
val Notification = BottomNavigationItem(title = "Notification",icon = Icons.Default.Notifications)
val Account = BottomNavigationItem(title = "Account",icon = Icons.Default.AccountCircle)

val items= listOf<BottomNavigationItem>(Home, Wallet, Notification, Account)

@Composable
@Preview
fun BottomNavigationBar() {
    NavigationBar {
        Row(
            modifier = Modifier.background(MaterialTheme.colorScheme.inverseOnSurface)
        ) {

            items.forEachIndexed { index, item ->
                NavigationBarItem(
                    selected = index == 0,
                    onClick = {},
                    icon = {
                        Icon(
                            imageVector = item.icon,
                            contentDescription = item.title,
                            tint = MaterialTheme.colorScheme.onBackground
                        )
                    },
                    label = {
                        Text(
                            text = item.title,
                            color = MaterialTheme.colorScheme.onBackground
                        )
                    }
                )
            }

        }
    }
}